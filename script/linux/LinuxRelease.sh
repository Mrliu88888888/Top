#!/bin/bash

AppName=`basename $0 | cut -d'.' -f1`
BasePath=$(cd `dirname $0`; pwd)
LibPath=$BasePath'/lib/'
LD_LIBRARY_PATH=$LibPath
export LD_LIBRARY_PATH
$BasePath/$AppName $@
