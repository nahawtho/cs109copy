import re
import sys

def f(x):
    return {
        '-p' : print(out)
    }
try:
    in_file = sys.argv[1]
    out_file = sys.argv[2] + '.csv'
    option = sys.argv[3]
    with open(in_file, 'r') as data:
        data = data.read().replace('],', ']\n')
        ms = re.findall("#TS:+\s+(\d+)", data)
        hr = re.findall("#rate:+\s+(\d+\.\d+)", data)
    for m, h in zip(ms,hr):
        rr = ((60)/float(h)) * 1000
        out += (m+', '+str(int(rr))+'\n') #ms and rr
    with open(out_file, 'w') as ofile:
        ofile.write(out) #writes csv
    f(x) # print to screen if -p typed

except:
    print('-Usage" type "python," "scripting2.py," the filepath(dragging from finder works) and your_reformatted_file_header')
    print('-(Filepath will look something like: /Users/rustinberlow/Desktop/1\ HRV\ during\ 7-11-10-59-40)')
    print('')
    sys.exit(0)