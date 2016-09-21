#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Thu Feb 12 22:54:21  2015

# from __future__ import with_statement
import sys
import os
import re
import datetime


def ensure_dir(dirname):
    if not dirname: return
    if os.path.isdir(dirname): return
    if not os.path.exists(dirname):
        os.makedirs(dirname)

def file_exists(filename):
    return os.path.exists(filename)

def prepare_timestamper(putlinefunc, comment = '//'):
    def puttimestamp():
        putlinefunc("{1} {0:s}".format(datetime.datetime.today().strftime("%a %b %d %H:%M:%S %Z %Y"), comment))
    return puttimestamp

def prepare_putline(stream, usetab = False, tablen = 4):
    if usetab:
        tab = '\t'
    else:
        tab = ' ' * tablen
    def putline(line = '', ind = 0):
        def indent(i = 0):
            return str(tab) * int(i)
        stream.write("{0}{1}\n".format(indent(ind), line))
    return putline

def prepare_commenter(putlinefunc, comment = '//'):
    def commenter(text = ''):
        putlinefunc('{1} {0:s}'.format(text, comment))
    return commenter

def prepare_openbrace(putlinefunc):
    def openbrace(indent = 0, text = ''):
        putlinefunc('{1} {0:s}'.format(text, '{'), indent)
    return openbrace

def prepare_closebrace(putlinefunc, semicolon = False):
    if semicolon:
        def closebrace(putsemicolon = True, indent = 0, text = ''):
            if putsemicolon:
                putlinefunc('{1}; {0:s}'.format(text, '}'), indent)
            else:
                putlinefunc('{1} {0:s}'.format(text, '}'), indent)
        return closebrace
    else:
        def closebrace(indent = 0, text = ''):
            putlinefunc('{1} {0:s}'.format(text, '}'), indent)
        return closebrace

def prepare_blankline(putlinefunc):
    def blankline():
        putlinefunc()
    return blankline

# One Definition Rule
def odr_definition(putline, classname):
    odr_def_symbol = '{0}_LIB_HEADER'.format(classname.upper())
    putline('#ifndef {0}'.format(odr_def_symbol))
    putline('#define {0}'.format(odr_def_symbol))

def file_name_ext(basename, ext = ''):
    return '{0}{2}{1}'.format(basename.lower(), ext, '.' if ext else '')

def source_file_name(mod_name, dir = '.'):
    return os.path.join(dir, file_name_ext(mod_name, 'cpp'))

def header_file_name(mod_name, dir = '.'):
    return os.path.join(dir, file_name_ext(mod_name, 'hpp'))

def make_file_name(dir, suffix = None):
    return os.path.join(dir, 'makefile') if not suffix else os.path.join(dir, 'make_{0}'.format(suffix))

def parse_arglists(args):
    result = dict()
    finder = re.compile(r"(?:\s*(?P<key>\w+)\s*=\s*(?P<value>\S+))", flags=re.I)
    while len(args):
        matcher = finder.search(args)
        if matcher:
            result[matcher.group('key')] = matcher.group('value')
            args = args[1 + matcher.end() : ]
        else:
            break
    return result

def create_module_source(modulename, dirname):
    filename = source_file_name(modulename, dirname)
    if file_exists(filename):
        print 'FILE "{0}" does exists, exiting'.format(filename)
        return
    
    with open(filename, 'w') as f:
        
        line = prepare_putline(f)
        puttime = prepare_timestamper(line)
        
        comment     = prepare_commenter(line)
        openbrace   = prepare_openbrace(line)
        closebrace  = prepare_closebrace(line)
        blankline   = prepare_blankline(line)
        #namespaced  = prepare_namespaced(classname, namespace = namespace)
        
        
        puttime()
        blankline()
        blankline()
        
        line('#include <avr/io.h>')
        comment('#include <inttypes.h>')
        comment('#include <avr/interrupt.h>')
        blankline()
        
        comment('#include "{0}"'.format(header_file_name(modulename, dir = '')))
        blankline()
        blankline()
        
        line('void setup()')
        openbrace()
        closebrace()
        blankline()
        
        line('// DO NOT FORGET INTERRUPTS!!!')
        line('// sei();')
        blankline()
        
        line('void loop()')
        openbrace()
        closebrace()
        blankline()
        
        line('int main()')
        openbrace()
        line('setup();', 1)
        line('while(1)', 1)
        openbrace(1)
        line('loop();', 2)
        closebrace(1)
        line('return 0;', 1)
        closebrace()
        
        blankline()
        blankline()
        
    pass

def create_class_source(classname, dirname):
    filename = source_file_name(classname, dirname)
    if file_exists(filename):
        print 'FILE "{0}" does exists, exiting'.format(filename)
        return
    
    with open(filename, 'w') as f:
        
        line = prepare_putline(f)
        puttime = prepare_timestamper(line)
        
        comment     = prepare_commenter(line)
        openbrace   = prepare_openbrace(line)
        closebrace  = prepare_closebrace(line)
        blankline   = prepare_blankline(line)
        
        puttime()
        blankline()
        blankline()
        
        line('#include "{0}"'.format(header_file_name(classname, dir = '')))
        blankline()
        blankline()
        
        line('{0}::{0}()'.format(classname))
        openbrace()
        closebrace()
        blankline()
        blankline()
        
        pass

def create_class_header(classname, dirname):
    filename = header_file_name(classname, dirname)
    if file_exists(filename):
        print 'FILE "{0}" does exists, exiting'.format(filename)
        return
    
    with open(filename, 'w') as f:
        
        line = prepare_putline(f)
        puttime = prepare_timestamper(line)
        
        comment     = prepare_commenter(line)
        openbrace   = prepare_openbrace(line)
        closebrace  = prepare_closebrace(line, True)
        blankline   = prepare_blankline(line)
        
        puttime()
        blankline()
        blankline()
        
        odr_definition(line, classname)
        blankline()
        
        line('#include <inttypes.h>')
        blankline()
        
        line('class {0}'.format(classname))
        openbrace()
        line('private:')
        line('{0}(const {0}&); // not implemented'.format(classname), 1)
        blankline()
        
        line('public:')
        
        line('{0}();'.format(classname), 1)
        blankline()
        
        closebrace()
        blankline()
        
        
        line('#endif')
        blankline()
        blankline()
    
    pass
    
def create_makefile(module_name, dirname):
    filename = make_file_name(dirname)
    if file_exists(filename):
        filename0 = make_file_name(dirname, suffix = module_name.lower())
        print 'FILE "{0}" does exists, trying diferent name {1}'.format(filename, filename0)
        #filename0 = make_file_name(dirname, suffix = module_name.lower())
        if file_exists(filename0):
            print 'FILE "{0}" does exists, exiting'.format(filename0)
            return
        filename = filename0
    
    with open(filename, 'w') as f:
        
        line = prepare_putline(f, True)
        puttime = prepare_timestamper(line, '#')
        
        comment     = prepare_commenter(line, '#')
        #openbrace   = prepare_openbrace(line)
        #closebrace  = prepare_closebrace(line, True)
        blankline   = prepare_blankline(line)
        
        puttime()
        comment('Autogenerated by script')
        blankline()
        line('BUILD_DIR = .')
        blankline()
        comment('============================================================')
        line('MAIN_NAME={0}_main'.format(module_name.lower()))
        line('{0}_LIB_NAME={1}'.format(module_name.upper(), module_name.lower()))
        line('{0}_OUTLIB_NAME={1}'.format(module_name.upper(), module_name.lower()))
        comment('============================================================')
        line('{0}_LIB_SRC=$({0}_LIB_NAME)'.format(module_name.upper()))
        comment('============================================================')
        blankline()
        #=============================================================
        line('DEFS=-DF_CPU=16000000L')
        blankline()
        
        line('PLATFORM = atmega2560')
        comment('PLATFORM = atmega328p')
        blankline()
        
        line('ifeq ($(PLATFORM), atmega2560)')
        comment('ATMEGA 2560 mcu')
        line('PROG_BAUD_RATE = 115200')
        line('PROGRAMMER = stk500v2')
        line('PORT = /dev/ttyACM0')
        
        line('else')
        blankline()
        line('ifeq ($(PLATFORM), atmega328p)')
        comment('ATMEGA 328p mcu')
        line('PROG_BAUD_RATE = 57600')
        line('PROGRAMMER = stk500v1')
        line('PORT = /dev/ttyUSB0')
        line('endif')
        line('endif')
        blankline()
        #==============================================================
        line('OUTPUT_TARGET=ihex')
        blankline()
        
        line('CPP=avr-g++')
        line('CC=avr-g++')
        line('C=avr-gcc')
        line('OBJCOPY=avr-objcopy')
        line('OBJDUMP=avr-objdump')
        line('STRIP=avr-strip')
        line('SIZE=avr-size')
        line('UPLOADER=avrdude')
        blankline()
        
        line('CFLAGS = -mmcu=$(PLATFORM) -Wall -Os -mcall-prologues -fno-exceptions $(DEFS)')
        blankline()
        
        comment('LDFLAGS = ')
        comment('LIBS= -lpthread')
        comment('============================================================')
        blankline()
        
        
        # hex file
        line('$(BUILD_DIR)/$(MAIN_NAME).hex: $(BUILD_DIR)/$(MAIN_NAME).elf ')
        line('$(OBJCOPY) -j .text -j .data -O $(OUTPUT_TARGET) $(BUILD_DIR)/$(MAIN_NAME).elf $(BUILD_DIR)/$(MAIN_NAME).hex', 1)
        blankline()

        # elf file
        line('$(BUILD_DIR)/$(MAIN_NAME).elf: $(BUILD_DIR)/$(MAIN_NAME).o $(BUILD_DIR)/$({0}_OUTLIB_NAME).o'.format(module_name.upper()))
        line('$(C) $(CFLAGS) -o $(BUILD_DIR)/$(MAIN_NAME).elf $(BUILD_DIR)/$(MAIN_NAME).o $(BUILD_DIR)/$({0}_OUTLIB_NAME).o'.format(module_name.upper()), 1)
        line('#$(STRIP) -s $(BUILD_DIR)/$(MAIN_NAME).elf')
        line('$(SIZE)  --mcu=$(PLATFORM) --format=avr $(BUILD_DIR)/$(MAIN_NAME).elf', 1)
        
        blankline()
        
        # main obj file
        line('$(BUILD_DIR)/$(MAIN_NAME).o: $(BUILD_DIR)/$(MAIN_NAME).cpp $({0}_LIB_SRC)/$({0}_LIB_NAME).hpp'.format(module_name.upper()))
        line('$(CPP) $(CFLAGS) -o $(BUILD_DIR)/$(MAIN_NAME).o -c $(BUILD_DIR)/$(MAIN_NAME).cpp', 1)
        blankline()
        
        # library object file
        line('# === library ====')
        line('$(BUILD_DIR)/$({0}_OUTLIB_NAME).o: $({0}_LIB_SRC)/$({0}_LIB_NAME).hpp $({0}_LIB_SRC)/$({0}_LIB_NAME).cpp'.format(module_name.upper()))
        line('$(CPP) $(CFLAGS) -o $(BUILD_DIR)/$({0}_OUTLIB_NAME).o -c $({0}_LIB_SRC)/$({0}_LIB_NAME).cpp'.format(module_name.upper()), 1)
        line('#=================')
        blankline()
        
        
        # asm 
        line('asm: $(BUILD_DIR)/$(MAIN_NAME).elf')
        line('$(OBJDUMP) -h -S  $(BUILD_DIR)/$(MAIN_NAME).elf >  $(BUILD_DIR)/$(MAIN_NAME).lst', 1)
        blankline()
        
        # map
        line('map: $(BUILD_DIR)/$(MAIN_NAME).elf')
        line('#$(C) -g -mmcu=$(PLATFORM) -Wl,-Map,$(BUILD_DIR)/$(MAIN_NAME).map -o $(BUILD_DIR)/$(MAIN_NAME).elf $(BUILD_DIR)/$(MAIN_NAME).o', 1)
        line('$(C) $(CFLAGS) -Wl,-Map,$(BUILD_DIR)/$(MAIN_NAME).map -o $(BUILD_DIR)/$(MAIN_NAME).elf $(BUILD_DIR)/$(MAIN_NAME).o', 1)
        blankline()
        
        # upload
        line('upload: $(BUILD_DIR)/$(MAIN_NAME).hex')
        line('@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"', 1)
        line('@echo "Upload $(PLATFORM) executable using [$(PROGRAMMER)] programmer. PORT:[$(PORT)] on [$(PROG_BAUD_RATE)] baud rate"', 1)
        line('@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"', 1)
        line('$(UPLOADER) -v -v -v -v  -p $(PLATFORM) -c $(PROGRAMMER) -P $(PORT) -b $(PROG_BAUD_RATE) -D -U flash:w:$(BUILD_DIR)/$(MAIN_NAME).hex:i', 1)
        blankline()
        
        # clean
        line('clean:')
        line('rm -f *.o *.hex $(BUILD_DIR)/$(MAIN_NAME).s $(BUILD_DIR)/$({0}_LIB_NAME).s $(BUILD_DIR)/$(MAIN_NAME).elf $(BUILD_DIR)/$(MAIN_NAME).map $(BUILD_DIR)/$(MAIN_NAME).lst'.format(module_name.upper()), 1)
        blankline()
        
        comment('============================================================')
        
        blankline()
        
        comment('trace assembler')
        comment('EXTRA_OPTS="-Wall -mmcu=$(PLATFORM) -x assembler-with-cpp"')
        comment('$(CPP) -Wa,--gstabs ${EXTRA_OPTS} -c -o foo.o foo.S')
        
        blankline()
        blankline()

    pass

def main():
    #print "Module avr_creator"
    
    if 2 > len(sys.argv):
        print 'Usage: {0} modulename [dir = dirname]'.format(sys.argv[0])
        raise SystemExit(1)
        
    module_name = sys.argv[1]
    argdict = parse_arglists(' '.join(sys.argv[2:]))
    print 'Using {0} name'.format(module_name)
    
    dirname = argdict.get('dir', module_name.lower())  #.lower()
    print 'Using "{0}" directory name'.format(dirname)
    ensure_dir(dirname)
    
    create_module_source('{0}_main'.format(module_name.lower()), dirname)
    #========================================================================
    
    classdir = os.path.join(dirname, module_name.lower())
    ensure_dir(classdir)
    
    
    create_class_source(module_name, classdir)
    create_class_header(module_name, classdir)
    #========================================================================
    
    create_makefile(module_name, dirname)
    
    pass
    

if __name__ == "__main__":
    sys.exit(main())



