# file makeall.sh
# make script for Fmnc combined daemon, release fmnccmbd_genio
# author Alexander Wirthmueller
# date created: 7 Mar 2016
# modified: 7 Mar 2016

make Fmnccmbd.h.gch

cd IexFmnc
make -j4
make install
cd ..

cd VecFmnc
make -j4
make install
cd ..

cd CrdFmncNav
make -j4
make install
cd ..

cd CrdFmncUsg
make -j4
make install
cd ..

cd CrdFmncUsr
make -j4
make install
cd ..

cd CrdFmncOrg
make -j4
make install
cd ..

cd CrdFmncPrs
make -j4
make install
cd ..

cd CrdFmncAdr
make -j4
make install
cd ..

cd CrdFmncFil
make -j4
make install
cd ..

cd CrdFmncStp
make -j4
make install
cd ..

cd CrdFmncPrj
make -j4
make install
cd ..

cd CrdFmncRun
make -j4
make install
cd ..

cd CrdFmncAct
make -j4
make install
cd ..

cd CrdFmncSep
make -j4
make install
cd ..

cd CrdFmncSmp
make -j4
make install
cd ..

cd CrdFmncFab
make -j4
make install
cd ..

cd CrdFmncFus
make -j4
make install
cd ..

cd CrdFmncTty
make -j4
make install
cd ..

cd CrdFmncTol
make -j4
make install
cd ..

cd CrdFmncFpj
make -j4
make install
cd ..

cd CrdFmncBil
make -j4
make install
cd ..

cd CrdFmncArt
make -j4
make install
cd ..

cd CrdFmncSki
make -j4
make install
cd ..

cd CrdFmncPco
make -j4
make install
cd ..

make -j4
make install

rm Fmnccmbd.h.gch

