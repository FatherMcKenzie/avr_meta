#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Thu Feb 19 01:50:17  2015

import sys


bauds_list = [2400, 4800, 9600, 14400, 19200, 28800, 38400, 56000, 57600, 76800, 115200, 128000, 153600, 230400, 256000, 460800, 921600]

def ubrr_val_0(baud, f_cpu = 16000000):
    return (f_cpu / (16 * baud)) - 1

def ubrr_val_1(baud, f_cpu = 16000000):
    return (f_cpu / (8 * baud)) - 1

def ubrr_val_syncmaster(baud, f_cpu = 16000000):
    return (f_cpu / (2 * baud)) - 1


def print_baudrates():
    for baud in bauds_list:
        print 'BAUD RATE : {0} = PRESCALER X1: {1}, PRESCALER X2: {2}, PRESCALER SM: {3}'.format(baud, ubrr_val_0(baud), ubrr_val_1(baud), ubrr_val_syncmaster(baud))
    pass


#==================================================================
# mode = 4 (16), 3 (8), 1 (2)


ASYNC_MODE_SINGLE = 4
ASYNC_MODE_DOUBLE = 3
SYNC_MASTER__MODE = 1

def baud_rate(ubrr_value, osc_freq = 16000000, mode = 4):
    return (osc_freq / (ubrr_value + 1)) >> mode
#==================================================================
def error_percent(value, reference_value):
    return 100.0 * (value - reference_value) / reference_value
#==================================================================

def ubrr_val_0_improved(baud, f_cpu = 16000000):  # SINGLE SPEED
    return ((((f_cpu / baud) >> 3) + 1) >> 1)  - 1

def ubrr_val_1_improved(baud, f_cpu = 16000000):  # DOUBLE SPEED
    return ((((f_cpu / baud) >> 2) + 1) >> 1) - 1

def ubrr_val_syncmaster_improved(baud, f_cpu = 16000000):
    return ((((f_cpu / baud) + 1) >> 1) - 1)      # SYNC MASTER 

def sign(val_l, val_r):
    return ' ' if (val_l == val_r) else '-' if (abs(val_l) < abs(val_r)) else '+'

def print_br_error(osc_freq = 16000000, mode = 4, func_simple = ubrr_val_0, func_impr = ubrr_val_0_improved):
    for baud in bauds_list:
        #ubrr_simple = func_simple(baud, osc_freq)
        #ubrr_improved = func_impr(baud, osc_freq)
        
        ubrr_simple   = 0x0FFF & func_simple(baud, osc_freq)
        ubrr_improved = 0x0FFF & func_impr(baud, osc_freq)
        
        baud_simple = baud_rate(ubrr_simple, osc_freq, mode)
        baud_improved = baud_rate(ubrr_improved, osc_freq, mode)
        
        err_simple   = error_percent(baud_simple, baud)
        err_improved = error_percent(baud_improved, baud)
        
        print 'baud:{0: >8}\tUBRR:{1: >8} err:{2: >8.4}\t  UBRR+:{3: >8} err:{4: >8.4}  \t{5}'.format(baud, ubrr_simple, err_simple, ubrr_improved, err_improved, sign(err_simple, err_improved))
        #print 'baud:{0: >8}\tUBRR: 0x{1:0>2X} err:{2: >8.4}\t  UBRR+: 0x{1:0>2X} err:{4: >8.4}  \t{5}'.format(baud, ubrr_simple, err_simple, ubrr_improved, err_improved, sign(err_simple, err_improved))
        

def print_br_x2_error(f_cpu = 16000000):
    for baud in bauds_list:
        ubrr_single_speed = ubrr_val_0_improved(baud, f_cpu)
        ubrr_double_speed = ubrr_val_1_improved(baud, f_cpu)
        
        baud_single = baud_rate(ubrr_single_speed, f_cpu, ASYNC_MODE_SINGLE)
        baud_double = baud_rate(ubrr_double_speed, f_cpu, ASYNC_MODE_DOUBLE)
        
        error_single = error_percent(baud_single, baud)
        error_double = error_percent(baud_double, baud)
        
        final_ubrr  = ubrr_double_speed if abs(error_double) < abs(error_single) else ubrr_single_speed
        final_x2    = 1 if abs(error_double) < abs(error_single) else 0
        
        final_mode = ASYNC_MODE_DOUBLE if final_x2 else ASYNC_MODE_SINGLE 
        final_baudrate = baud_rate(final_ubrr, f_cpu, final_mode)
        final_error = error_percent(final_baudrate, baud)
        
        print 'baud:{0: >7}    UBRR:{1: >4} ERR:{2: >8.4}    UBRR:{3: >4} ERR:{4: >8.4}  :  UBRR:{5: >4} X2:{6} ERR:{7: >8.4}'.format(baud, ubrr_single_speed,error_single,ubrr_double_speed,error_double,final_ubrr,final_x2,final_error)
        


def main():

    OSC_FREQ = 16000000
    print "Module bauds"
    
    
    print_br_x2_error(OSC_FREQ)
    
    
    '''
    #print_baudrates()
    print '{0:=^64}'.format('NORMAL MODE')
    print_br_error(osc_freq = OSC_FREQ)
    print '{0:=^64}'.format('DOUBLE FREQ')
    print_br_error(osc_freq = OSC_FREQ, mode = 3, func_simple = ubrr_val_1, func_impr = ubrr_val_1_improved)
    print '{0:=^64}'.format('SYNC MASTER')
    print_br_error(osc_freq = OSC_FREQ, mode = 1, func_simple = ubrr_val_syncmaster, func_impr = ubrr_val_syncmaster_improved)
    '''
    
    
    
    
    pass

if __name__ == "__main__":
    sys.exit(main())
