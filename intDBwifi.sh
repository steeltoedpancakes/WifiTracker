 #!/bin/bash
#sqlite3 wifiData.db "create table address(mac varchar(17), lastSeen date primary key(mac))";
#sqlite3 wifiData.db "create table namedMac(mac varchar(17), name varchar(55));"  
sqlite3 wifiData.db "create table addressAlt (mac varchar(17) PRIMARY KEY, lastSeen date);"

#join statment for intersect of two sets 
#select * from address join addressAlt on address.mac=addressAlt.mac;

