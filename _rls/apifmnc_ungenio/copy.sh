# file copy.sh
# copy script for Fmnc API library, release apifmnc_ungenio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

export set SRCROOT=/Users/epsi/src

mkdir $SRCROOT/apifmnc

cp makeall.sh $SRCROOT/apifmnc/

cp Makefile $SRCROOT/apifmnc/

cp ../../apifmnc/*.h $SRCROOT/apifmnc/
cp ../../apifmnc/*.cpp $SRCROOT/apifmnc/

