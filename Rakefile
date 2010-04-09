require 'rake'
require 'rake/clean'

NAME    = 'mehmulator'
VERSION = '0.0.1'

CFLAGS  = "-Os -Wall -Wno-invalid-offsetof -fno-exceptions -fno-rtti -D___VERSION___='\"#{VERSION}\"' -Isources/BackEnd/nanojit/nanojit -DFEATURE_NANOJIT"
LDFLAGS = ''

CLEAN.include('sources/**/*.o')

SOURCES = FileList.new

BACKEND = FileList['sources/BackEnd/**/*.cpp']

HOST = ENV['HOST']

case HOST

when /PSP/i
    CC = 'psp-g++'
    AR = 'psp-ar'

    INTERFACE = 'PSP'
    OUT       = 'EBOOT.PBP'

else
    CC = 'g++'
    AR = 'ar'

    INTERFACE = 'wx'
    OUT       = NAME

end

FRONTEND = FileList["sources/FrontEnd/#{INTERFACE}/**/*.cpp"]

SOURCES.include(BACKEND)
SOURCES.include(FRONTEND)

OBJECTS = SOURCES.ext('o')

task :default => [OUT]

rule '.o' => '.cpp' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :compile => OBJECTS

file OUT => :compile do
    if HOST == 'PSP'
        Makefile = File.new('Makefile', 'w')

        Makefile.write <<MAKEFILE
TARGET = #{OUT}
OBJS   = #{OBJECTS}

CFLAGS   = #{CFLAGS}
CXXFLAGS = #{CFLAGS}
ASFLAGS  = #{CFLAGS}
LIBS     = -lSDL_image -lSDL -lSDLmain -lGL -lpsprtc -lpspvfpu -lpspirkeyb -lpsppower -lc -lpng -ljpeg -lpspgu -lpsphprm -lpspaudio -lm -lz

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = #{NAME}

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak 
MAKEFILE

        Makefile.close
    else
        sh "#{CC} #{CFLAGS} -o #{OUT} #{OBJECTS} #{LDFLAGS}"
    end
end
