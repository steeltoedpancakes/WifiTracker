#!/bin/bash
sqlite3 wifiData.db "ALTER TABLE wifiData.address RENAME TO address %s;"