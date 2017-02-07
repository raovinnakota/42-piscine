#!/bin/bash
ldapsearch -Q "(uid=z*)" | sort -r  | grep cn:
