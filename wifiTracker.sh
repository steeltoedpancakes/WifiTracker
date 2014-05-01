 #!/bin/bash
s=0
while read f ; do 
    #echo "$f" 
    #h = ${f:0:1}
    if [ "${f:0:1}" == "S" -o "${f:1:1}" == "S" ];
    then
	s=1
	echo "s = 1"
    else
	
	 echo ${f:0:17}
	    #echo "date" ${f:19:10}
	    #echo "time" ${f:30:8}
            sqlite3 wifiData.db  "insert into addressAlt (mac, lastSeen) values('${f:0:17}','${f:19:10}');"
	
    fi
done <test-01.csv

