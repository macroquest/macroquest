all: traverse

clean: traverse_clean

DIRECTORIES=\
    MQ2Main \
    MacroQuest \
    MQ2Chat \
    MQ2ChatWnd \
    MQ2EQBugFix \
    MQ2FPS \
    MQ2ItemDisplay \
    MQ2Labels \
    MQ2Map \
    MQ2Template \
    mq2telnet


traverse: $(DIRECTORIES)
    for %a in ($(DIRECTORIES)) do nmake DIRECTORY=%a COMMAND=all traverse_directory

traverse_clean: $(DIRECTORIES)
    for %a in ($(DIRECTORIES)) do nmake DIRECTORY=%a COMMAND=clean traverse_directory


traverse_directory:
    cd $(MAKEDIR)\$(DIRECTORY)
    nmake $(COMMAND)
