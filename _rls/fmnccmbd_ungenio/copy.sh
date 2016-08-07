# file copy.sh
# copy script for Fmnc combined daemon, release fmnccmbd_ungenio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

export set SRCROOT=/Users/epsi/src
export set LIBROOT=/Users/epsi/lib
export set BINROOT=/Users/epsi/bin

mkdir $SRCROOT/fmnccmbd
mkdir $SRCROOT/fmnccmbd/IexFmnc
mkdir $SRCROOT/fmnccmbd/VecFmnc
mkdir $SRCROOT/fmnccmbd/CrdFmncNav
mkdir $SRCROOT/fmnccmbd/CrdFmncUsg
mkdir $SRCROOT/fmnccmbd/CrdFmncUsr
mkdir $SRCROOT/fmnccmbd/CrdFmncOrg
mkdir $SRCROOT/fmnccmbd/CrdFmncPrs
mkdir $SRCROOT/fmnccmbd/CrdFmncAdr
mkdir $SRCROOT/fmnccmbd/CrdFmncFil
mkdir $SRCROOT/fmnccmbd/CrdFmncStp
mkdir $SRCROOT/fmnccmbd/CrdFmncPrj
mkdir $SRCROOT/fmnccmbd/CrdFmncRun
mkdir $SRCROOT/fmnccmbd/CrdFmncAct
mkdir $SRCROOT/fmnccmbd/CrdFmncSep
mkdir $SRCROOT/fmnccmbd/CrdFmncSmp
mkdir $SRCROOT/fmnccmbd/CrdFmncFab
mkdir $SRCROOT/fmnccmbd/CrdFmncFus
mkdir $SRCROOT/fmnccmbd/CrdFmncTty
mkdir $SRCROOT/fmnccmbd/CrdFmncTol
mkdir $SRCROOT/fmnccmbd/CrdFmncFpj
mkdir $SRCROOT/fmnccmbd/CrdFmncBil
mkdir $SRCROOT/fmnccmbd/CrdFmncArt
mkdir $SRCROOT/fmnccmbd/CrdFmncSki
mkdir $SRCROOT/fmnccmbd/CrdFmncPco

mkdir $LIBROOT/fmnccmbd

mkdir $BINROOT/fmnccmbd

cp makeall.sh $SRCROOT/fmnccmbd/

cp Makefile $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/Fmnccmbd.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/Fmnccmbd.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/FmnccmbdAppsrv.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/FmnccmbdAppsrv.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/FmnccmbdJobprc.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/FmnccmbdJobprc.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/FmnccmbdOpprc.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/FmnccmbdOpprc.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/Fmnccmbd_exe.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/Fmnccmbd_exe.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/Fmnc.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/Fmnc.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/Root*.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/Root*.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/Sess*.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/Sess*.cpp $SRCROOT/fmnccmbd/

cp ../../fmnccmbd/gbl/*.h $SRCROOT/fmnccmbd/
cp ../../fmnccmbd/gbl/*.cpp $SRCROOT/fmnccmbd/

cp Makefile_IexFmnc $SRCROOT/fmnccmbd/IexFmnc/Makefile

cp ../../fmnccmbd/IexFmnc/IexFmnc*.h $SRCROOT/fmnccmbd/IexFmnc/
cp ../../fmnccmbd/IexFmnc/IexFmnc*.cpp $SRCROOT/fmnccmbd/IexFmnc/

cp Makefile_VecFmnc $SRCROOT/fmnccmbd/VecFmnc/Makefile

cp ../../fmnccmbd/VecFmnc/Vec*.h $SRCROOT/fmnccmbd/VecFmnc/
cp ../../fmnccmbd/VecFmnc/Vec*.cpp $SRCROOT/fmnccmbd/VecFmnc/

cp Makefile_CrdFmncNav $SRCROOT/fmnccmbd/CrdFmncNav/Makefile

cp ../../fmnccmbd/CrdFmncNav/*.h $SRCROOT/fmnccmbd/CrdFmncNav/
cp ../../fmnccmbd/CrdFmncNav/*.cpp $SRCROOT/fmnccmbd/CrdFmncNav/

cp Makefile_CrdFmncUsg $SRCROOT/fmnccmbd/CrdFmncUsg/Makefile

cp ../../fmnccmbd/CrdFmncUsg/*.h $SRCROOT/fmnccmbd/CrdFmncUsg/
cp ../../fmnccmbd/CrdFmncUsg/*.cpp $SRCROOT/fmnccmbd/CrdFmncUsg/

cp Makefile_CrdFmncUsr $SRCROOT/fmnccmbd/CrdFmncUsr/Makefile

cp ../../fmnccmbd/CrdFmncUsr/*.h $SRCROOT/fmnccmbd/CrdFmncUsr/
cp ../../fmnccmbd/CrdFmncUsr/*.cpp $SRCROOT/fmnccmbd/CrdFmncUsr/

cp Makefile_CrdFmncOrg $SRCROOT/fmnccmbd/CrdFmncOrg/Makefile

cp ../../fmnccmbd/CrdFmncOrg/*.h $SRCROOT/fmnccmbd/CrdFmncOrg/
cp ../../fmnccmbd/CrdFmncOrg/*.cpp $SRCROOT/fmnccmbd/CrdFmncOrg/

cp Makefile_CrdFmncPrs $SRCROOT/fmnccmbd/CrdFmncPrs/Makefile

cp ../../fmnccmbd/CrdFmncPrs/*.h $SRCROOT/fmnccmbd/CrdFmncPrs/
cp ../../fmnccmbd/CrdFmncPrs/*.cpp $SRCROOT/fmnccmbd/CrdFmncPrs/

cp Makefile_CrdFmncAdr $SRCROOT/fmnccmbd/CrdFmncAdr/Makefile

cp ../../fmnccmbd/CrdFmncAdr/*.h $SRCROOT/fmnccmbd/CrdFmncAdr/
cp ../../fmnccmbd/CrdFmncAdr/*.cpp $SRCROOT/fmnccmbd/CrdFmncAdr/

cp Makefile_CrdFmncFil $SRCROOT/fmnccmbd/CrdFmncFil/Makefile

cp ../../fmnccmbd/CrdFmncFil/*.h $SRCROOT/fmnccmbd/CrdFmncFil/
cp ../../fmnccmbd/CrdFmncFil/*.cpp $SRCROOT/fmnccmbd/CrdFmncFil/

cp Makefile_CrdFmncStp $SRCROOT/fmnccmbd/CrdFmncStp/Makefile

cp ../../fmnccmbd/CrdFmncStp/*.h $SRCROOT/fmnccmbd/CrdFmncStp/
cp ../../fmnccmbd/CrdFmncStp/*.cpp $SRCROOT/fmnccmbd/CrdFmncStp/

cp Makefile_CrdFmncPrj $SRCROOT/fmnccmbd/CrdFmncPrj/Makefile

cp ../../fmnccmbd/CrdFmncPrj/*.h $SRCROOT/fmnccmbd/CrdFmncPrj/
cp ../../fmnccmbd/CrdFmncPrj/*.cpp $SRCROOT/fmnccmbd/CrdFmncPrj/

cp Makefile_CrdFmncRun $SRCROOT/fmnccmbd/CrdFmncRun/Makefile

cp ../../fmnccmbd/CrdFmncRun/*.h $SRCROOT/fmnccmbd/CrdFmncRun/
cp ../../fmnccmbd/CrdFmncRun/*.cpp $SRCROOT/fmnccmbd/CrdFmncRun/

cp Makefile_CrdFmncAct $SRCROOT/fmnccmbd/CrdFmncAct/Makefile

cp ../../fmnccmbd/CrdFmncAct/*.h $SRCROOT/fmnccmbd/CrdFmncAct/
cp ../../fmnccmbd/CrdFmncAct/*.cpp $SRCROOT/fmnccmbd/CrdFmncAct/

cp Makefile_CrdFmncSep $SRCROOT/fmnccmbd/CrdFmncSep/Makefile

cp ../../fmnccmbd/CrdFmncSep/*.h $SRCROOT/fmnccmbd/CrdFmncSep/
cp ../../fmnccmbd/CrdFmncSep/*.cpp $SRCROOT/fmnccmbd/CrdFmncSep/

cp Makefile_CrdFmncSmp $SRCROOT/fmnccmbd/CrdFmncSmp/Makefile

cp ../../fmnccmbd/CrdFmncSmp/*.h $SRCROOT/fmnccmbd/CrdFmncSmp/
cp ../../fmnccmbd/CrdFmncSmp/*.cpp $SRCROOT/fmnccmbd/CrdFmncSmp/

cp Makefile_CrdFmncFab $SRCROOT/fmnccmbd/CrdFmncFab/Makefile

cp ../../fmnccmbd/CrdFmncFab/*.h $SRCROOT/fmnccmbd/CrdFmncFab/
cp ../../fmnccmbd/CrdFmncFab/*.cpp $SRCROOT/fmnccmbd/CrdFmncFab/

cp Makefile_CrdFmncFus $SRCROOT/fmnccmbd/CrdFmncFus/Makefile

cp ../../fmnccmbd/CrdFmncFus/*.h $SRCROOT/fmnccmbd/CrdFmncFus/
cp ../../fmnccmbd/CrdFmncFus/*.cpp $SRCROOT/fmnccmbd/CrdFmncFus/

cp Makefile_CrdFmncTty $SRCROOT/fmnccmbd/CrdFmncTty/Makefile

cp ../../fmnccmbd/CrdFmncTty/*.h $SRCROOT/fmnccmbd/CrdFmncTty/
cp ../../fmnccmbd/CrdFmncTty/*.cpp $SRCROOT/fmnccmbd/CrdFmncTty/

cp Makefile_CrdFmncTol $SRCROOT/fmnccmbd/CrdFmncTol/Makefile

cp ../../fmnccmbd/CrdFmncTol/*.h $SRCROOT/fmnccmbd/CrdFmncTol/
cp ../../fmnccmbd/CrdFmncTol/*.cpp $SRCROOT/fmnccmbd/CrdFmncTol/

cp Makefile_CrdFmncFpj $SRCROOT/fmnccmbd/CrdFmncFpj/Makefile

cp ../../fmnccmbd/CrdFmncFpj/*.h $SRCROOT/fmnccmbd/CrdFmncFpj/
cp ../../fmnccmbd/CrdFmncFpj/*.cpp $SRCROOT/fmnccmbd/CrdFmncFpj/

cp Makefile_CrdFmncBil $SRCROOT/fmnccmbd/CrdFmncBil/Makefile

cp ../../fmnccmbd/CrdFmncBil/*.h $SRCROOT/fmnccmbd/CrdFmncBil/
cp ../../fmnccmbd/CrdFmncBil/*.cpp $SRCROOT/fmnccmbd/CrdFmncBil/

cp Makefile_CrdFmncArt $SRCROOT/fmnccmbd/CrdFmncArt/Makefile

cp ../../fmnccmbd/CrdFmncArt/*.h $SRCROOT/fmnccmbd/CrdFmncArt/
cp ../../fmnccmbd/CrdFmncArt/*.cpp $SRCROOT/fmnccmbd/CrdFmncArt/

cp Makefile_CrdFmncSki $SRCROOT/fmnccmbd/CrdFmncSki/Makefile

cp ../../fmnccmbd/CrdFmncSki/*.h $SRCROOT/fmnccmbd/CrdFmncSki/
cp ../../fmnccmbd/CrdFmncSki/*.cpp $SRCROOT/fmnccmbd/CrdFmncSki/

cp Makefile_CrdFmncPco $SRCROOT/fmnccmbd/CrdFmncPco/Makefile

cp ../../fmnccmbd/CrdFmncPco/*.h $SRCROOT/fmnccmbd/CrdFmncPco/
cp ../../fmnccmbd/CrdFmncPco/*.cpp $SRCROOT/fmnccmbd/CrdFmncPco/

