#define INCL_PM
#include <OS2.H>
/*
  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
  ³ PMSW program entry                                            ³
  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
 void main ( void)
 {
 HAB       hAnchorBlock;    /* Anchor-block handle */
 int       iRC=0;           /* return code from program */
 ULONG     ulRetCode=0;     /* Return code *from Win* functions */
 ULONG     ulSendResult=0;  /* Return code *from Win* functions */
 HMQ       hMsgQWindow;
 QMSG      rMsgQWin;
 QMSG      rMsgDESK;

 if (( hAnchorBlock = WinInitialize( 0UL )) == NULLHANDLE)
   return;
 if ((hMsgQWindow=WinCreateMsgQueue(hAnchorBlock, 0UL))== NULLHANDLE)
   return;
 rMsgDESK.hwnd=HWND_DESKTOP;
 rMsgDESK.msg=0;
 rMsgDESK.mp1=MPVOID;
 rMsgDESK.mp2=MPVOID;
 rMsgDESK.time=0;
 rMsgDESK.reserved=0;
 ulSendResult=WinBroadcastMsg(HWND_DESKTOP,
   WM_SYSCOMMAND,
   MPFROMSHORT(SC_CLOSE),
   MPFROM2SHORT(CMDSRC_MENU,FALSE),
   (ULONG) BMSG_FRAMEONLY);
 WinShutDownSystem(HWND_DESKTOP,rMsgDESK);
 WinDestroyMsgQueue(hMsgQWindow); /* Destroy message queue   */
 WinTerminate(hAnchorBlock);    /* Deregister application    */
 return;
}
