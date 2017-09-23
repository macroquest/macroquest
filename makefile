!if exist(extra.mak)
!include extra.mak
!endif

all: mq2main/mq2auth0.h traverse

clean: traverse_clean

DIRECTORIES=\
    MQ2Main \
    MQ2Chat \
    MQ2ChatWnd \
    MQ2EQBugFix \
    MQ2ItemDisplay \
    MQ2Labels \
    MQ2Map \
    MQ2Template \
    mq2telnet \
    MQ2Bzsrch \
    MQ2IRC \
    MQ2CustomBinds \
    MQ2EQIM \
    MQ2HUD \
    $(DIRECTORIES)


mq2main/mq2auth0.h: mq2auth.exe always
    mq2auth

traverse: $(DIRECTORIES)
    for %a in ($(DIRECTORIES)) do nmake DIRECTORY=%a COMMAND=all traverse_directory

traverse_clean: $(DIRECTORIES)
    for %a in ($(DIRECTORIES)) do nmake DIRECTORY=%a COMMAND=clean traverse_directory


traverse_directory:
    cd "$(MAKEDIR)\$(DIRECTORY)"
    nmake $(COMMAND)


always:
