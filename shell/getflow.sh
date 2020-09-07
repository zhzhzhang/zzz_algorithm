#!/bin/bash
i=0
for line in 'cat server_ips.txt'
do
    ips[$i]=line
    let i++
done
cd /usr/local/hbase/bin
for num in ${ips[*]}
do
    echo "scan '$1',{PREFIXFILTER=>'A|$2'}" |hbase shell > /home/hadoop/zzz/1S.txt
    echo "scan '$1',{PREFIXFILTER=>'B|$2'}" |hbase shell > /home/hadoop/zzz/1D.txt
done