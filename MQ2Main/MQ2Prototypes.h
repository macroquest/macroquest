namespace MQ2Prototypes
{
typedef PCHAR   (__stdcall *fEQGetStringByID)(DWORD);
typedef VOID    (__cdecl *fEQCommand)(PSPAWNINFO, PCHAR);
typedef HRESULT (__stdcall *fGetDeviceState)(THIS_ DWORD, LPVOID);
typedef DWORD   (__stdcall *fEQScreenItem)(DWORD, DWORD, DWORD);
typedef DWORD   (__stdcall *fEQScreenSpawn)(DWORD, DWORD);
typedef PCHAR   (__stdcall *fEQNewUIINI)(VOID);
typedef VOID    (__cdecl   *fEQMemSpell)(DWORD,DWORD);
typedef VOID    (__cdecl *fEQLoadSpells)(PSPELLFAVORITE,DWORD);
typedef VOID    (__cdecl *fEQSelectItem)(int,DWORD);//public: void __thiscall CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *)
typedef VOID    (__cdecl *fEQBuyItem)(int);//private: void __thiscall CMerchantWnd::RequestBuyItem(int)
typedef VOID    (__cdecl *fEQSellItem)(int);//private: void __thiscall CMerchantWnd::RequestSellItem(int)
typedef VOID    (__cdecl *fEQWriteMapfile)(PCHAR, int);//void __thiscall ZZZ::WriteMapfile(PCHAR zonename, int Layer);
typedef BOOL    (__cdecl *fEQProcGameEvts)(VOID);
typedef VOID    (__cdecl *fEQSendMessage)(PVOID,DWORD,PVOID,DWORD,BOOL);

typedef DWORD (__cdecl *fMQParm)(PCHAR, PCHAR, PSPAWNINFO);

/* PLUGINS */
typedef DWORD   (__cdecl *fMQWriteChatColor)(PCHAR Line, DWORD Color, DWORD Filter);
typedef VOID  (__cdecl *fMQPulse)(VOID);
typedef DWORD  (__cdecl *fMQIncomingChat)(PCHAR Line, DWORD Color);
typedef VOID  (__cdecl *fMQInitializePlugin)(VOID);
typedef VOID  (__cdecl *fMQShutdownPlugin)(VOID);
typedef VOID  (__cdecl *fMQZoned)(VOID);
typedef VOID  (__cdecl *fMQReloadUI)(VOID);
typedef VOID  (__cdecl *fMQCleanUI)(VOID);
typedef VOID  (__cdecl *fMQDrawHUD)(VOID);
typedef VOID  (__cdecl *fMQSetGameState)(DWORD GameState);
};
using namespace MQ2Prototypes;