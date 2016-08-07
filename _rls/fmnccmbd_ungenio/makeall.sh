# file makeall.sh
# make script for Fmnc combined daemon, release fmnccmbd_ungenio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

make Fmnccmbd.h.gch

cd IexFmnc
make -j2
make install
cd ..

cd VecFmnc
make -j2
make install
cd ..

cd CrdFmncNav
make -j2
make install
cd ..

cd CrdFmncUsg
make -j2
make install
cd ..

cd CrdFmncUsr
make -j2
make install
cd ..

cd CrdFmncOrg
make -j2
make install
cd ..

cd CrdFmncPrs
make -j2
make install
cd ..

cd CrdFmncAdr
make -j2
make install
cd ..

cd CrdFmncFil
make -j2
make install
cd ..

cd CrdFmncStp
make -j2
make install
cd ..

cd CrdFmncPrj
make -j2
make install
cd ..

cd CrdFmncRun
make -j2
make install
cd ..

cd CrdFmncAct
make -j2
make install
cd ..

cd CrdFmncSep
make -j2
make install
cd ..

cd CrdFmncSmp
make -j2
make install
cd ..

cd CrdFmncFab
make -j2
make install
cd ..

cd CrdFmncFus
make -j2
make install
cd ..

cd CrdFmncTty
make -j2
make install
cd ..

cd CrdFmncTol
make -j2
make install
cd ..

cd CrdFmncFpj
make -j2
make install
cd ..

cd CrdFmncBil
make -j2
make install
cd ..

cd CrdFmncArt
make -j2
make install
cd ..

cd CrdFmncSki
make -j2
make install
cd ..

cd CrdFmncPco
make -j2
make install
cd ..

make -j2
make install

rm Fmnccmbd.h.gch

