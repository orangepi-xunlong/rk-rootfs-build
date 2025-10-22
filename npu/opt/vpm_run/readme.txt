vpm_run is testing framework for VIPLite driver. It can run all networks by configuring sample.txt. 


How to build vpm_run?
1. modify toolchain in build_tst_sample.sh
2. export VIPLITE_ROOT="viplite root path"
3. ./build_tst_sample.sh


vpm_run usage: 
              vpm_run + sample.txt

Example:
        ./vpm_run sample.txt


How to write a sample.txt?

[network]
#the path of NBG file.
[input]
#network's inputs. It can be multiple.
[golden]
#golden files for this NBG. It can be multiple.

example 1:
[network]
./lenet.nb
[input]
./input.dat
[golden]
./output.dat

example 2:
[network]
./ssd_mobilenet.nb
[input]
./input_1.dat
[golden]
./output_1.dat
./output_2.dat






