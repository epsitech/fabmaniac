# file copy.sh
# copy script for Fmnc database access library, release dbsfmnc_ungenio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

export set SRCROOT=/Users/epsi/src

mkdir $SRCROOT/dbsfmnc

cp makeall.sh $SRCROOT/dbsfmnc/

cp Makefile $SRCROOT/dbsfmnc/

cp ../../dbsfmnc/DbsFmnc.h $SRCROOT/dbsfmnc/
cp ../../dbsfmnc/DbsFmnc.cpp $SRCROOT/dbsfmnc/
cp ../../dbsfmnc/Fmnc*.h $SRCROOT/dbsfmnc/
cp ../../dbsfmnc/Fmnc*.cpp $SRCROOT/dbsfmnc/
cp ../../dbsfmnc/VecFmnc*.h $SRCROOT/dbsfmnc/
cp ../../dbsfmnc/VecFmnc*.cpp $SRCROOT/dbsfmnc/

