#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Sun May 25 16:55:33  2014

#from __future__ import with_statement
import sys
import os
#import subprocess
import datetime
import re


class Namespace(object):
    def __init__(self, initial):
        pattern = r"\W"
        self.ns = list()
        for item in re.split(pattern, initial):
            if len(item): self.ns.append(item)
        
    def getNameSpace(self):
        return '::'.join(self.ns)

    def getOdrPrefix(self, delim='_'):
        return delim.join(self.ns).upper()
        
    def getFilePrefix(self, delim='_'):
        if len(self.ns):
            return "{0}{1}".format(delim.join(self.ns).lower(), delim)
        return ''
        
    def openNamespace(self, putline):
        if 0 == len(self.ns): return
        for item in self.ns:
            putline('namespace {0}'.format(item), 0)
            putline('{', 0)
        
    def closeNamespace(self, putline):
        if 0 == len(self.ns): return
        for item in reversed(self.ns):
            putline('{1} // {0} namespace'.format(item, '}'), 0)

    def empty(self):
        return 0 == len(self.ns)
    
    def qualified_name(self, symbol_name):
        return symbol_name if self.empty() else '::'.join([self.getNameSpace(), symbol_name])


class Indenter(object):

    def __init__(self, ind = 0):
        self.indent=ind
        
    def increase(self):
        self.indent += 1
        
    def decrease(self):
        if 0 < self.indent:
            self.indent -= 1
        
        
    def current(self):
        return self.indent


def is_camel_case(class_name):
    """
        returns True if input class_name is in CamelCase,
        otherwise returns False (use snake case) 
    """
    if class_name.islower() or class_name.count('_'):
        return False
    return True


def ensure_dir(dirname):
    if not dirname: return
    if 0 == len(dirname): return
    if os.path.isdir(dirname): return
    if not os.path.exists(dirname):
        os.makedirs(dirname)

def prepare_putline(stream, indentobj, usetab = False, tablen = 4):
    if usetab:
        tab = '\t'
    else:
        tab = ' ' * tablen
    #tab = '\t' if usetab or tab = ' '*tablen
    def putline(line = '', ind = -1):
        def indent(i = -1):
            if -1 == i: return str(tab) * indentobj.current()
            else: return str(tab) * int(i)
        stream.write("{0}{1}\n".format(indent(ind), line))
    return putline

def gettestname(class_name, usecamelcase, prefix = "test"):
    if usecamelcase:
        return "{0}{1}".format(prefix.capitalize(), class_name)
    return "{0}_{1}".format(prefix, class_name)

def prepare_timestamper(putlinefunc, comment = '//'):
    def puttimestamp():
        putlinefunc("{1} {0:s}".format(datetime.datetime.today().strftime("%a %b %d %H:%M:%S %Z %Y"), comment))
    return puttimestamp

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

def getfilename(classname, ext = "hpp", dirname = '', prefix = '', delim = '_'):
    if len(prefix):
        class_name = '{0}{1}{2}'.format(prefix, delim, classname)
    else:
        class_name = classname
    if len(dirname):
        return "{2}/{0}.{1}".format(class_name.lower(), ext, dirname)
    else:
        return "{0}.{1}".format(class_name.lower(), ext)

def class_src_filename(classname, dirname = '', prefix = '', prefixdelim = '_'):
    return getfilename(classname, ext = "cpp", dirname = dirname, prefix = prefix, delim = prefixdelim)

def class_hdr_filename(classname, dirname = '', prefix = '', prefixdelim = '_'):
    return getfilename(classname, ext = "hpp", dirname = dirname, prefix = prefix, delim = prefixdelim)

def prepare_commenter(putlinefunc, comment = '//'):
    def commenter(text = ''):
        putlinefunc('{1} {0:s}'.format(text, comment))
    return commenter

def prepare_openbrace(putlinefunc, indentobj):
    def openbrace(text = ''):
        putlinefunc('{1} {0:s}'.format(text, '{'), indentobj.current())
        indentobj.increase()
    return openbrace

def prepare_closebrace(putlinefunc, indentobj, semicolon = False):
    if semicolon:
        def closebrace(putsemicolon = True, text = ''):
            indentobj.decrease()
            if putsemicolon:
                putlinefunc('{1}; {0:s}'.format(text, '}'), indentobj.current())
            else:
                putlinefunc('{1} {0:s}'.format(text, '}'), indentobj.current())
        return closebrace
    else:
        def closebrace(text = ''):
            indentobj.decrease()
            putlinefunc('{1} {0:s}'.format(text, '}'), indentobj.current())
        return closebrace

def prepare_blankline(putlinefunc):
    def blankline():
        putlinefunc()
    return blankline

def prepare_namespaced(classname, namespace = ''):
    def namespaced(methodname):
        if len(namespace):
            return '{2}::{1}::{0}'.format(methodname, classname, namespace)
        return '{1}::{0}'.format(methodname, classname)
    return namespaced

def getdefinitionguardname(classname, prefix = ''):
    if len(prefix):
        return "{1}_{0}_CLASS_HEADER".format(classname.upper(), prefix)
    return "{0}_CLASS_HEADER".format(classname.upper())

def get_doxy_block(liner, blank):
    def doxygen_block(doctext):
        blank()
        liner('/**')
        for line in doctext:
            liner(' * {0}'.format(line))
        liner(' */')
    return doxygen_block

def main():
    print "Module classtestcreator"
    if 2 > len(sys.argv):
        print "usage: {0:s} ClassName [base = BaseClass] [ns = namespace] [dir = targetdirectory]".format(sys.argv[0])
        raise SystemExit(1)
    
    
    NUMBER_OF_TESTS = 6

    classname = sys.argv[1]    # classname
    argdict = parse_arglists(' '.join(sys.argv[2:]))
    
    #CAMEL_CASE, SNAKE_CASE = xrange(2)
    usecamelcase = is_camel_case(classname)
    
    testclass =  gettestname(classname, usecamelcase) #testclassname
    baseclass = argdict.get('base', '') #baseclassname
    
    namespace = Namespace(argdict.get('ns', '')) #namespace
    directory = argdict.get('dir', classname.lower()) # target directory
    
    print 'Class name      : [{0}]'.format(classname)
    print 'Test class name : [{0}]'.format(testclass)
    print 'Base class name : [{0}]'.format(baseclass)
    print 'Namespace       : [{0}]'.format(namespace.getNameSpace())
    print 'Namespace prefix: [{0}]'.format(namespace.getOdrPrefix())
    print 'Namespace file  : [{0}]'.format(namespace.getFilePrefix())
    
    print 'Directory       : [{0}]'.format(directory)

    srcfilename = class_src_filename(classname, directory) #, namespace.getFilePrefix())
    hdrfilename = class_hdr_filename(classname, directory) #, namespace.getFilePrefix())

    testsrcfilename = class_src_filename(testclass, directory) #, namespace.getFilePrefix())
    testhdrfilename = class_hdr_filename(testclass, directory)

    
    print 'source      : [{0}]'.format(srcfilename)
    print 'header      : [{0}]'.format(hdrfilename)
    print 'test source : [{0}]'.format(testsrcfilename)
    print 'test header : [{0}]'.format(testhdrfilename)
    
    class_obj_file_base_name = "{1}{0}".format(classname.lower(), namespace.getFilePrefix())
    #test_obj_file_base_name = "{1}{0}".format(testclass.lower(), namespace.getFilePrefix())
    test_obj_file_base_name = "{1}_{0}".format(class_obj_file_base_name, 'test')
    
    print 'class obj   : [{0}]'.format(class_obj_file_base_name)
    print 'test obj    : [{0}]'.format(test_obj_file_base_name)
    
    
    ensure_dir(directory)
    #=============================================================
    # Creating source file
    indent = Indenter(0)
    fobj = open(srcfilename, 'w')
    line = prepare_putline(fobj, indent)
    timestamp = prepare_timestamper(line, comment = '//')
    comment = prepare_commenter(line)
    openbrace = prepare_openbrace(line, indent)
    closebrace = prepare_closebrace(line, indent)
    blankline = prepare_blankline(line)
    #namespaced = prepare_namespaced(classname, namespace = namespace.getNameSpace())

    timestamp()
    blankline()
    #comment('Created by Class creator')
    blankline()
    line('#include "{0}"'.format(getfilename(classname, ext = "hpp")))

    
    blankline()
    blankline()
    
    namespace.openNamespace(line)
    
    blankline()


    line('{0}::{0}()'.format(classname))
    if len(baseclass):
        line(':{0}()'.format(baseclass), 1)
    
    openbrace()
    closebrace()
    blankline()
    
    line('#if 0', 0)

    line('{0}::~{0}()'.format(classname))
    openbrace()
    closebrace()
    blankline()
    
    line('{0}::{0}(const {0}& other)'.format(classname))
    openbrace()
    closebrace()
    blankline()
    
    line('{0}& {0}::operator = (const {0}& other)'.format(classname))
    openbrace()
    line('if(&other != this)')
    openbrace()
    line('// code here')
    closebrace()
    line('return *this;')
    closebrace()
    blankline()
    
    line('#endif', 0)
    
    namespace.closeNamespace(line)

    fobj.close()

    #=============================================================
    # Creating header file
    indent = Indenter(0)
    fobj = open(hdrfilename, 'w')
    line = prepare_putline(fobj, indent)
    timestamp = prepare_timestamper(line, comment = '//')
    comment = prepare_commenter(line)
    openbrace = prepare_openbrace(line, indent)
    closebrace = prepare_closebrace(line, indent, semicolon = True)
    blankline = prepare_blankline(line)
    namespaced = prepare_namespaced(classname, namespace = namespace.getNameSpace())
    doxygen = get_doxy_block(line, blankline)

    timestamp()
    blankline()
    #comment('Created by Class creator')
    blankline()
    blankline()

    line('#ifndef {0}'.format(getdefinitionguardname(classname, namespace.getOdrPrefix())))
    line('#define {0}'.format(getdefinitionguardname(classname, namespace.getOdrPrefix())))
    blankline()

    if len(baseclass):
        line('#include <{0}>'.format(baseclass))
    comment('#include <>')
    comment('#include <>')
    blankline()
    

    line('#ifdef UNITTEST_MODE')
    line('namespace tut')
    openbrace()
    line('template<class T> class test_object;')
    closebrace()
    line('#endif')

    blankline()

    #line('#ifdef TEST_PRINT')
    #line('#include <iostream>')
    #line('#endif')

    blankline()
    namespace.openNamespace(line)
    blankline()
    blankline()



    if len(baseclass):
        line('class {0} : public {1}'.format(classname, baseclass))
    else:
        line('class {0}'.format(classname))
    
    openbrace()
    line('#ifdef UNITTEST_MODE', 0)
    line('template<class T> friend class tut::test_object;')
    line('#endif', 0)
    
    blankline()
    line('public:', 0)
    
    doxygen(["\\brief Brief description which ends at this dot.", "", "Details follow here."])
    
    doxygen(["default constructor"])
    line('{0}();'.format(classname), 1)
    blankline()
    
    line('#if 0', 0)
    
    doxygen(["destructor"])
    line('~{0}();'.format(classname), 1)

    blankline()
    doxygen(["copy constructor", "\\param other"])
    line('{0}(const {0}& other);'.format(classname), 1)
    
    blankline()
    doxygen(["assignment operator", "\\param other"])
    line('{0}& operator = (const {0} &other);'.format(classname))
    
    line('#endif', 0)

    closebrace()
    blankline()
    namespace.closeNamespace(line)
    
    line ('#endif')
    fobj.close()

    #=============================================================
    # Creating test file
    indent = Indenter(0)
    fobj = open(testsrcfilename, 'w')
    line = prepare_putline(fobj, indent)
    timestamp = prepare_timestamper(line, comment = '//')
    comment = prepare_commenter(line)
    openbrace = prepare_openbrace(line, indent)
    closebrace = prepare_closebrace(line, indent)
    blankline = prepare_blankline(line)
    #namespaced = prepare_namespaced(classname, namespace = namespace.getNameSpace())

    timestamp()
    blankline()
    comment('Created by Class creator script')
    blankline()
    blankline()

    
    #line('#include "{0}"'.format(testhdrfilename))
    line('#include "{0}"'.format(getfilename(testclass, ext = "hpp")))
    #line('#include <tut_reporter.h>')
    line('#include <tut/tut_reporter.hpp>')
    line('#include <iostream>')
    
    blankline()
    blankline()
    

    line('namespace tut')
    openbrace()
    line('test_runner_singleton runner;')
    closebrace()
    blankline()
    
    line('int main()')
    openbrace()
    line('tut::reporter reporter;')
    line('tut::runner.get().set_callback(&reporter);')
    blankline()
    line('tut::runner.get().run_tests();')
    blankline()
    line('return !reporter.all_ok();')
    closebrace()
    fobj.close()
    
    #==============================================================
    # create test header class
    
    indent = Indenter(0)
    fobj = open(testhdrfilename, 'w')
    line = prepare_putline(fobj, indent)
    timestamp = prepare_timestamper(line, comment = '//')
    comment = prepare_commenter(line)
    openbrace = prepare_openbrace(line, indent)
    closebrace = prepare_closebrace(line, indent)
    closebrace_semocolon = prepare_closebrace(line, indent, semicolon = True)
    blankline = prepare_blankline(line)

    def create_test(testnum):
        blankline()
        line('template<>')
        line('template<>')
        line('void testobject::test<{0}>()'.format(testnum))
        openbrace()
        line('set_test_name("test_{0:0>4}");'.format(testnum))
        blankline()
        
        #line('{0} s;'.format('::'.join([namespace.getNameSpace(), classname])))
        line('{0} s;'.format(namespace.qualified_name(classname)))
        
        
        line('ensure_equals("message", 42, 42);')
        closebrace()
        blankline()
        
    timestamp()
    blankline()
    blankline()
    
    line('#include <tut/tut.hpp>')
    line('#include "{0}"'.format(getfilename(classname, ext = "hpp")))
    blankline()
    
    line('namespace tut')
    openbrace()
    #blankline()
    line('struct data{};')
    #openbrace()
    #closebrace_semocolon()
    #blankline()
    
    line('typedef tut::test_group<tut::data> tg;')
    line('tg testgroup("first_test_group");')
    #blankline()
    line('typedef tg::object testobject;')
    blankline()
    blankline()


    create_test(1)
    blankline()
    line('#if 0', 0)
    blankline()

    start = 2
    for testnum in xrange(start, NUMBER_OF_TESTS + start):
        create_test(testnum)
    
    blankline()
    line('#endif', 0)
    
    closebrace()
    fobj.close()
    
    #===============================================================
    # create makefile
    
    indent = Indenter(0)
    
    fobj = open("{1}/{0}".format('makefile', directory), 'w')
    
    line = prepare_putline(fobj, indent)
    timestamp = prepare_timestamper(line, comment = '#')
    comment = prepare_commenter(line, comment = '#')
    openbrace = prepare_openbrace(line, indent)
    closebrace = prepare_closebrace(line, indent)
    closebrace_semocolon = prepare_closebrace(line, indent, semicolon = True)
    blankline = prepare_blankline(line)
    timestamp()
    comment('Autogenerated by class creater script')
    blankline()
    
    #test_obj_file_base_name
    
    mf_unit_test_dir = 'UNITTESTDIR'
    mf_install_dir = 'INSTALLDIR'
    mf_test_name = 'TESTNAME'
    mf_out_test_name = 'OUTTESTNAME'
    mf_class_name = 'CLASSNAME'
    mf_out_class_name = 'OUTCLASSNAME'
    
    line('{0} = ../unittest'.format(mf_unit_test_dir))
    line('SRCDIR = .')
    line('{0} = ../unittest'.format(mf_install_dir))
    comment('=' * 64)
    line('{0}={1}'.format(mf_test_name, testclass.lower()))
    #line('{0}={1}{2}'.format(mf_out_test_name, namespace.getFilePrefix(), testclass.lower()))
    line('{0}={1}'.format(mf_out_test_name, test_obj_file_base_name))
    line('{0}={1}'.format(mf_class_name, classname.lower()))
    line('{0}={1}{2}'.format(mf_out_class_name, namespace.getFilePrefix(), classname.lower()))
    comment('=' * 64)
    line('DEFS=-DUNITTEST_MODE')
    line('CPP=g++')
    line('CC=g++')
    line('C=gcc')
    line('STRIP=strip')
    blankline()
    line('CFLAGS = -Wall -Wcpp -Wextra -Weffc++ -O2 $(DEFS)')
    comment('LDFLAGS = ')
    comment('LIBS= -lpthread')
    comment('=' * 64)
    
    line('$({0}): $({0}).o $({1}).o'.format(mf_out_test_name, mf_out_class_name))
    line('\tmkdir -p $({0})'.format(mf_unit_test_dir))
    line('\t$(CPP) $(CFLAGS) $(LDFLAGS) -o $({0})/$({1}) $({1}).o $({2}).o $(LIBS)'.format(mf_unit_test_dir, mf_out_test_name, mf_out_class_name))
    comment('\t$(STRIP) -s $({0})'.format(mf_out_test_name))
    blankline()
    
    line('$({0}).o: $(SRCDIR)/$({1}).hpp $(SRCDIR)/$({2}).hpp'.format(mf_out_test_name, mf_test_name, mf_class_name))
    line('\t$(CPP) $(CFLAGS) -o $(SRCDIR)/$({0}).o -c $(SRCDIR)/$({1}).cpp'.format(mf_out_test_name, mf_test_name))
    blankline()
    
    line('$({0}).o: $(SRCDIR)/$({1}).hpp $(SRCDIR)/$({1}).cpp'.format(mf_out_class_name, mf_class_name))
    line('\t$(CPP) $(CFLAGS) -o $(SRCDIR)/$({0}).o -c $(SRCDIR)/$({1}).cpp'.format(mf_out_class_name, mf_class_name))
    blankline()
    
    line('clean:')
    line('\trm -f *.o')
    blankline()
    
    
    fobj.close()
    
    


if __name__ == "__main__":
    sys.exit(main())



