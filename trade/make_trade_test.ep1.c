#########################################################################
#   ���  ��������                                                    #
#            �Σԣԥǡ����̿��������                                   #
#            ��ͻ�����ƥ��������  ����ͻ�����ƥ������               #
#                                                                       #
#   ����ʪ  �ף���  �ӣ��������  ��                                #
#               �ӣ�������  �ͣ���������  �У������    #
#           �ӣͣ�  �ᥤ���ե�����                                      #
#           �ʣӣգ��ѣӣͣж�ͭ�饤�֥���                            #
#########################################################################

#########################################################################
#                                                                       #
#      ���󥯥롼�ɥե������ѥǥ��쥯�ȥ�                               #
#                                                                       #
#########################################################################
# TRADE�ѥإå��ե�����
TRADEH = /usr/rev/TRADE/include
TRADEHINS = /usr/rev/TRADE/include_ins
TRADETHSOR = /home/jimmy/10-17-02

# TRADE�ʥƥ����ѡ˥إå��ե�����
TRADETH = /usr/rev/TRADE/inc
TRADETHINS = /usr/rev/TRADE/include_ins

NTOK = /opt/FJSVsblp/include

#########################################################################
#                                                                       #
#      �������ե������ѥǥ��쥯�ȥ�                                     #
#                                                                       #
#########################################################################
tradesrc = /usr/rev/TRADE/src
dmysrc = /home/jimmy/10-17-02


#########################################################################
#                                                                       #
#      ���֥������ȡ��饤�֥���ѥǥ��쥯�ȥ�                           #
#                                                                       #
#########################################################################
tradeobj = /home/jimmy/10-17-02/obj

#lib    = ../../LIB/SMPLIB/smp.so
lib    = /home/jimmy/10-17-02/main_pr


#########################################################################
#                                                                       #
#      ����ѥ��륳�ޥ��                                               #
#                                                                       #
#########################################################################
CC     = gcc


#########################################################################
#                                                                       #
#      ����ѥ��륪�ץ����                                             #
#                                                                       #
#########################################################################
CFLAGS = -I$(TRADEH) \
         -I$(TRADEHINS) \
	 -I$(NTOK)

#         -I$(TRADETH) \
#        -I$(TRADETHINS)



########################################################################
#      �ޥ��󤴤Ȥ�����                                                #
#                                                                      #
#    -DEWS   :�Σţ�  �ţףӣ��������ʣţףӡݣգء���(Rel 4.0)��      #
#    -DSUNC  :�ӣգ�  �ӣУ��ңã��ʣӣ���ϣӣ��������ء�             #
#    -DDS    :�ٻ���  �ģӣ��������ʣգأС��ģӡ�                     #
#    -DAIX32 :�ɣ£�  �ңӣ��������ʣ��ɣأ�������                     #
#    -DHI_UX :��Ω    �����������ҡʣȣɡݣգء��ףţ���               #
########################################################################
#    -D SOFT      ... ���եȥ��������ȤΥǥХå��Ķ������             #
#    -D DEBUG     ... �ǥХå��ѥ�å�����������ɸ����Ϥ���           #
#    -D DEBUG0    ... ɬ�׺Ǿ��¤ΥǥХå��ѥ�å�������ɸ����Ϥ���   #
#    -D DEBUG1    ... ��å���������ɸ����Ϥ���                     #
#    -D DBGSIGINT ... ����ȥ���äγ����ߤ�ͭ���ˤ���             #
#    -D DBGKILL   ... �����ƥཪλ������λ���˥�����򻦤��ʤ�         #
########################################################################
OPT    = -D DEBUG -g -Wall
#OPT    = -ggdb
#OPT    = -D DBGKILL -D SUNC
#OPT    = -D DBGKILL -D DBGSIGINT -D SUNC
#OPT    = -D DBGKILL -D DBGSIGINT -D DEBUG1 -D SUNC
#########################################################################
#                                                                       #
#      �ԣң��ģ��ѥ��󥯥롼�ɥե�����                                 #
#                                                                       #
#########################################################################
FILES = $(TRADEHINS)/os_EBPC.h \
        $(TRADEHINS)/os_ECNC.h \
        $(TRADEHINS)/os_EFLC.h \
        $(TRADEHINS)/os_EMBC.h \
        $(TRADEHINS)/os_EPBC.h \
        $(TRADEHINS)/os_EPRC.h \
        $(TRADEHINS)/os_ERDC.h \
        $(TRADEHINS)/os_ESBP.h \
        $(TRADEHINS)/os_ESEC.h \
        $(TRADEHINS)/os_ESMC.h \
        $(TRADEHINS)/os_ESYS.h \
        $(TRADEHINS)/os_ETRD.h \
        $(TRADEHINS)/os_ESMQ.h \
        $(TRADEHINS)/os_EMMC.h \
        $(TRADEHINS)/os_ERDC.h \
	$(TRADEHINS)/os_ETMC.h \
        $(TRADEH)/oscom.h \
        $(TRADEHINS)/os_debug.h \
        $(TRADEHINS)/os_ptr_ins.h \
        $(TRADEHINS)/oscom_ins.h \
        $(TRADEHINS)/os_EMBC_ins.h \
        $(TRADEHINS)/os_ETMC_ins.h \
        $(TRADEHINS)/os_ESBP_ins.h \
        $(TRADEHINS)/os_EBPC_ins.h \
        $(TRADEHINS)/os_ESMC_ins.h \
	$(TRADEHINS)/oscremb_ins.h \
	$(TRADEHINS)/oscrepr_ins.h \
	$(TRADEH)/oscrepr.h \
	$(TRADEH)/oscremb.h \
        $(TRADEHINS)/os_SG_ins.h \
	$(TRADEHINS)/osfrpbf_ins.h \
	$(TRADEH)/osfrpbf.h \
	$(TRADEH)/os_initSystem.h \
	$(TRADEHINS)/os_initSystem_ins.h \
	$(TRADEHINS)/os_Date2DayTime_ins.h \
	$(TRADEHINS)/osgtdat_ins.h \
	$(TRADEH)/osgtdat.h \
	$(TRADEHINS)/osgtpbf_ins.h \
	$(TRADEH)/osgtdat.h \
	$(TRADEHINS)/oscrelbp_ins.h \
	$(TRADEH)/oscrelbp.h \
	$(TRADETHSOR)/ossenms_ins.h \
	$(TRADETHSOR)/ossenms.h \
	$(TRADETHSOR)/os_endProcess.h \
	$(TRADETHSOR)/os_endProcess_ins.h \
	$(TRADETHSOR)/os_GetEbpcTableInd_ins.h \
        $(TRADETHSOR)/u_mpf.h
        

   #$(TRADEHINS)/os_ptrEXT_ins.h \
	     


#########################################################################
#                                                                       #
#      ���֥������ȥե�����                                             #
#                                                                       #
#########################################################################
#objtrade = $(tradeobj)/os_initSystem.o \
	   $(tradeobj)/os_initTrade.o \
           $(tradeobj)/os_initSG.o \
           $(tradeobj)/os_startSG.o \
           $(tradeobj)/os_endSG.o \
           $(tradeobj)/os_getSG.o \
           $(tradeobj)/os_freeSG.o \
           $(tradeobj)/os_initEPRC.o \
           $(tradeobj)/os_initEBPC.o \
           $(tradeobj)/os_initEFLC.o \
           $(tradeobj)/os_initESMC.o \
           $(tradeobj)/os_initESBP.o \
           $(tradeobj)/os_initEPBC.o \
           $(tradeobj)/os_initEMBC.o \
           $(tradeobj)/os_initEMMC.o \
           $(tradeobj)/os_initERDC.o \
	   $(tradeobj)/os_initETMC.o \
	   $(tradeobj)/os_MyEMBC.o \
	   $(tradeobj)/os_MyEPRC.o \
           $(tradeobj)/os_initProcess.o \
	   $(tradeobj)/osgtdat.o \
	   $(tradeobj)/os_Date2DayTime.o \
	   $(tradeobj)/oscrepr.o \
	   $(tradeobj)/os_GstPrSep.o \
	   $(tradeobj)/osfrpbf.o \
	   $(tradeobj)/oscremb.o \
	   $(tradeobj)/osgtpbf.o \
	   $(tradeobj)/os_GetEbpcTableInd.o \
	   $(tradeobj)/oscrelbp.o \
	   $(tradeobj)/fdebug.o \
	   $(tradeobj)/os_KeyGen.o 
           


objtrade = /usr/rev/TRADE/lib/libmtre.so

objdmy = $(tradeobj)/main_pr.o \
	 $(tradeobj)/BlpMpf.o \
	 $(tradeobj)/oswrite1.o \

# $(tradeobj)/os_cretrc.o \
# $(tradeobj)/oswrite1.o \
# $(tradeobj)/os_trcget.o \

#########################################################################
#                                                                       #
#      �饤�֥��������ޥ��                                           #
#                                                                       #
#########################################################################
#$(lib)/smp.so : $(objcmn) \
#               $(objocp) \
#               $(objfip) \
#               $(objmcp) \
#               $(objscp) \
#               $(objstp) 
#	@echo "�ӣͣХ饤�֥������桦����"
#	@ld -o $(lib)/smp.so $(objcom) $(objocp) $(objfip) $(objmcp) \
#               $(objscp) $(objstp) $(OBJ) $(OBJWIN)
#	@echo "��������λ������"
#
#########################################################################
$(lib) : $(objtrade) \
         $(objdmy)
	@echo "�̣ɣΣգ��ѣԣң��ģŶ�ͭ�饤�֥������桦����"
#	@ld -G -o $(lib) $(objcom) $(objocp) $(objfip) -dy
#	@gcc -o $(lib) $(objcom) $(objocp) $(objfip) $(objdmy)
#	@gcc -o $(lib) $(objcom) $(objfip) $(objdmy)
#	@gcc -o $(lib) $(objcom) $(objocp) $(objfip) $(objdmy) $(objdmp)
	@gcc -o $(lib) $(objtrade) $(objdmy) -lc -lpthread -lnsl
	@echo "��������λ������"


#########################################################################
#                                                                       #
#      �ԣң��ģŴؿ�����ѥ��륳�ޥ��                                 #
#                                                                       #
#########################################################################
$(tradeobj)/os_MyEPRC.o  :  $(tradesrc)/os_MyEPRC.c 
	@echo "����ѥ����桦���� os_MyEPRC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_MyEPRC.c
	@mv os_MyEPRC.o $(tradeobj)/os_MyEPRC.o

$(tradeobj)/oscrelbp.o  :  $(tradesrc)/oscrelbp.c 
	@echo "����ѥ����桦���� oscrelbp.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/oscrelbp.c
	@mv oscrelbp.o $(tradeobj)/oscrelbp.o

$(tradeobj)/os_MyEMBC.o  :  $(tradesrc)/os_MyEMBC.c
	@echo "����ѥ����桦���� os_MyEMBC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_MyEMBC.c
	@mv os_MyEMBC.o $(tradeobj)/os_MyEMBC.o

$(tradeobj)/os_initEMBC.o  :  $(tradesrc)/os_initEMBC.c 
	@echo "����ѥ����桦���� os_initEMBC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initEMBC.c
	@mv os_initEMBC.o $(tradeobj)/os_initEMBC.o

$(tradeobj)/os_initESEC.o  :  $(tradesrc)/os_initESEC.c 
	@echo "����ѥ����桦���� os_initESEC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initESEC.c
	@mv os_initESEC.o $(tradeobj)/os_initESEC.o

$(tradeobj)/os_initETMC.o  :  $(tradesrc)/os_initETMC.c 
	@echo "����ѥ����桦���� os_initETMC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initETMC.c
	@mv os_initETMC.o $(tradeobj)/os_initETMC.o

$(tradeobj)/os_initTrade.o  :  $(tradesrc)/os_initTrade.c
	@echo "����ѥ����桦���� os_initTrade.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initTrade.c
	@mv os_initTrade.o $(tradeobj)/os_initTrade.o

$(tradeobj)/os_initEPRC.o  :  $(tradesrc)/os_initEPRC.c 
	@echo "����ѥ����桦���� os_initEPRC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initEPRC.c
	@mv os_initEPRC.o $(tradeobj)/os_initEPRC.o

$(tradeobj)/os_initSystem.o  :  $(tradesrc)/os_initSystem.c 
	@echo "����ѥ����桦���� os_initSystem.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initSystem.c
	@mv os_initSystem.o $(tradeobj)/os_initSystem.o

$(tradeobj)/os_initEBPC.o  :  $(tradesrc)/os_initEBPC.c 
	@echo "����ѥ����桦���� os_initEBPC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initEBPC.c
	@mv os_initEBPC.o $(tradeobj)/os_initEBPC.o

$(tradeobj)/os_initEFLC.o  :  $(tradesrc)/os_initEFLC.c 
	@echo "����ѥ����桦���� os_initEFLC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initEFLC.c
	@mv os_initEFLC.o $(tradeobj)/os_initEFLC.o

$(tradeobj)/os_initESMC.o  :  $(tradesrc)/os_initESMC.c 
	@echo "����ѥ����桦���� os_initESMC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initESMC.c
	@mv os_initESMC.o $(tradeobj)/os_initESMC.o

$(tradeobj)/os_initESBP.o  :  $(tradesrc)/os_initESBP.c 
	@echo "����ѥ����桦���� os_initESBP.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initESBP.c
	@mv os_initESBP.o $(tradeobj)/os_initESBP.o

$(tradeobj)/os_initEPBC.o  :  $(tradesrc)/os_initEPBC.c
	@echo "����ѥ����桦���� os_initEPBC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initEPBC.c
	@mv os_initEPBC.o $(tradeobj)/os_initEPBC.o

$(tradeobj)/os_initSG.o  :  $(tradesrc)/os_initSG.c 
	@echo "����ѥ����桦���� os_initSG.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initSG.c
	@mv os_initSG.o $(tradeobj)/os_initSG.o

$(tradeobj)/os_startSG.o  :  $(tradesrc)/os_startSG.c 
	@echo "����ѥ����桦���� os_startSG.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_startSG.c
	@mv os_startSG.o $(tradeobj)/os_startSG.o

$(tradeobj)/os_endSG.o  :  $(tradesrc)/os_endSG.c 
	@echo "����ѥ����桦���� os_endSG.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_endSG.c
	@mv os_endSG.o $(tradeobj)/os_endSG.o

$(tradeobj)/os_getSG.o  :  $(tradesrc)/os_getSG.c 
	@echo "����ѥ����桦���� os_getSG.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_getSG.c
	@mv os_getSG.o $(tradeobj)/os_getSG.o

$(tradeobj)/os_freeSG.o  :  $(tradesrc)/os_freeSG.c 
	@echo "����ѥ����桦���� os_freeSG.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_freeSG.c
	@mv os_freeSG.o $(tradeobj)/os_freeSG.o

$(tradeobj)/os_initProcess.o  :  $(tradesrc)/os_initProcess.c 
	@echo "����ѥ����桦���� os_initProcess.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initProcess.c
	@mv os_initProcess.o $(tradeobj)/os_initProcess.o

$(tradeobj)/os_initEMMC.o  :  $(tradesrc)/os_initEMMC.c 
	@echo "����ѥ����桦���� os_initEMMC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initEMMC.c
	@mv os_initEMMC.o $(tradeobj)/os_initEMMC.o

$(tradeobj)/os_initERDC.o  :  $(tradesrc)/os_initERDC.c 
	@echo "����ѥ����桦���� os_initERDC.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_initERDC.c
	@mv os_initERDC.o $(tradeobj)/os_initERDC.o

$(tradeobj)/osgtdat.o  : $(tradesrc)/osgtdat.c 
	@echo "����ѥ����桦����osgtdat.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/osgtdat.c
	@mv osgtdat.o $(tradeobj)/osgtdat.o

$(tradeobj)/os_Date2DayTime.o  : $(tradesrc)/os_Date2DayTime.c 
	@echo "����ѥ����桦����osgtdat.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_Date2DayTime.c
	@mv os_Date2DayTime.o $(tradeobj)/os_Date2DayTime.o

$(tradeobj)/oscrepr.o  : $(tradesrc)/oscrepr.c 
	@echo "����ѥ����桦����oscrepr.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/oscrepr.c
	@mv oscrepr.o $(tradeobj)/oscrepr.o

$(tradeobj)/oscremb.o  : $(tradesrc)/oscremb.c 
	@echo "����ѥ����桦����v.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/oscremb.c
	@mv oscremb.o $(tradeobj)/oscremb.o

$(tradeobj)/os_KeyGen.o  : $(tradesrc)/os_KeyGen.c 
	@echo "����ѥ����桦����os_KeyGen.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_KeyGen.c
	@mv os_KeyGen.o $(tradeobj)/os_KeyGen.o

$(tradeobj)/os_GstPrSep.o  : $(tradesrc)/os_GstPrSep.c 
	@echo "����ѥ����桦����os_GstPrSep.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_GstPrSep.c
	@mv os_GstPrSep.o $(tradeobj)/os_GstPrSep.o

$(tradeobj)/osfrpbf.o  : $(tradesrc)/osfrpbf.c 
	@echo "����ѥ����桦����osfrpbf.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/osfrpbf.c
	@mv osfrpbf.o $(tradeobj)/osfrpbf.o

$(tradeobj)/osgtpbf.o  : $(tradesrc)/osgtpbf.c 
	@echo "����ѥ����桦����osgtpbf.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/osgtpbf.c
	@mv osgtpbf.o $(tradeobj)/osgtpbf.o

$(tradeobj)/os_GetEbpcTableInd.o  : $(tradesrc)/os_GetEbpcTableInd.c 
	@echo "����ѥ����桦����os_GetEbpcTableInd.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/os_GetEbpcTableInd.c
	@mv os_GetEbpcTableInd.o $(tradeobj)/os_GetEbpcTableInd.o

$(tradeobj)/fdebug.o  :  $(tradesrc)/fdebug.c 
	@echo "����ѥ����桦���� fdebug.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(tradesrc)/fdebug.c
	@mv fdebug.o $(tradeobj)/fdebug.o

#########################################################################
#                                                                       #
#      ���ߡ��ؿ�����ѥ��륳�ޥ��                                     #
#                                                                       #
#########################################################################
$(tradeobj)/BlpMpf.o  : $(dmysrc)/BlpMpf.c 
	@echo "����ѥ����桦����BlpMpf.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(dmysrc)/BlpMpf.c
	@mv BlpMpf.o $(tradeobj)/BlpMpf.o

$(tradeobj)/os_trcget.o  : $(dmysrc)/os_trcget.c 
	@echo "����ѥ����桦����os_trcget.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(dmysrc)/os_trcget.c
	@mv os_trcget.o $(tradeobj)/os_trcget.o

#$(tradeobj)/main_sy.o  : $(dmysrc)/main_sy.c 
#	@echo "����ѥ����桦����main_sy.c"
#	@$(CC) $(CFLAGS) $(OPT) -c $(dmysrc)/main_sy.c
#	@mv main_sy.o $(tradeobj)/main_sy.o

$(tradeobj)/oswrite1.o  : $(dmysrc)/oswrite1.c 
	@echo "����ѥ����桦����oswrite1.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(dmysrc)/oswrite1.c
	@mv oswrite1.o $(tradeobj)/oswrite1.o

$(tradeobj)/main_pr.o  : $(dmysrc)/main_pr.c 
	@echo "����ѥ����桦����main_pr.c"
	@$(CC) $(CFLAGS) $(OPT) -c $(dmysrc)/main_pr.c
	@mv main_pr.o $(tradeobj)/main_pr.o



###################  �ţΣġ��ϣơ��ƣɣ̣�  ############################
