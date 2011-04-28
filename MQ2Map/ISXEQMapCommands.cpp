#include "../MQ2Plugin.h"
#include "MQ2Map.h"

VOID MapFilterSetting( DWORD nMapFilter, int arg, int argc, char *argv[])
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR Buff[MAX_STRING]={0};
    DWORD dwValue = 0;
    PCHAR szFilterMap[] = {
        "hide",
        "show",
        NULL
    };
    PMAPFILTER pMapFilter=&MapFilterOptions[nMapFilter];
    if (!RequirementsMet(nMapFilter))
    {
        WriteChatf("'%s' requires '%s' option.  Please enable this option first.",pMapFilter->szName,MapFilterOptions[pMapFilter->RequiresOption].szName);
        return;
    }
    if (arg>=argc) 
    {
        // NO VALUE
        char szBuffer[2048]={0};
        if (pMapFilter->bIsToggle) 
        {
            sprintf(szBuffer,"%s: %s",pMapFilter->szName,szFilterMap[pMapFilter->Enabled]);
        } 
        else if (nMapFilter == MAPFILTER_Custom) 
        {
            if (IsOptionEnabled(nMapFilter)==0)
            {
                sprintf(szBuffer,"%s: Off",pMapFilter->szName);
            } 
            else 
            {
                sprintf(szBuffer,"%s: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&MapFilterCustom));
            }
        } 
        else 
        {
            sprintf(szBuffer,"%s: %d",pMapFilter->szName,pMapFilter->Enabled);
        }
        if (pMapFilter->DefaultColor != -1) 
        {
            CHAR szBuffer2[MAX_STRING] = {0};
            DWORD R,G,B;
            R= (pMapFilter->Color&0xFF0000)/0x10000;
            G= (pMapFilter->Color&0xFF00)/0x100;
            B= pMapFilter->Color&0xFF;
            WriteChatf("%s (Color: %d %d %d)",szBuffer,R,G,B);
        }
        else
            WriteChatf("%s",szBuffer);
        return;
    } 


    if (pMapFilter->bIsToggle) 
    {
        if (!stricmp(szFilterMap[0],argv[arg])) 
        {
            pMapFilter->Enabled = 0;
        } 
        else if (!stricmp(szFilterMap[1],argv[arg])) 
        {
            pMapFilter->Enabled = 1;
        } 
        else 
        {
            pMapFilter->Enabled = 1 - pMapFilter->Enabled;
        }
        WriteChatf("%s is now set to: %s",pMapFilter->szName,szFilterMap[IsOptionEnabled(nMapFilter)]);
    } 
    else if (nMapFilter == MAPFILTER_Custom)
    {
        ClearSearchSpawn(&MapFilterCustom);
        {
            pMapFilter->Enabled = 1;
            ParseSearchSpawn(arg+1,argc,argv,MapFilterCustom);
            WriteChatf("%s is now set to: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&MapFilterCustom));
        }
    } 
    else 
    {
        pMapFilter->Enabled = atoi(argv[arg]);
        WriteChatf("%s is now set to: %d",pMapFilter->szName,pMapFilter->Enabled);
    }

    itoa(pMapFilter->Enabled,szBuffer,10);
    pISInterface->SetSettingi("ISXEQMap.xml","Map Filters",pMapFilter->szName,pMapFilter->Enabled);
    pISInterface->SaveSettings("ISXEQMap.xml");
}

int CMD_MapFilter(int argc, char *argv[])
{
    // Display settings
    if (argc<2) 
    {
        WriteChatColor("Map filtering settings:",USERCOLOR_DEFAULT);
        WriteChatColor("-----------------------",USERCOLOR_DEFAULT);
        for (DWORD i=0;MapFilterOptions[i].szName!=NULL;i++) 
            if (RequirementsMet(i))
                MapFilterSetting(i,argc,argc,argv);

        return 0;
    } 

    if (!stricmp(argv[1],"help")) 
    {
        // Display Help
        WriteChatColor("Map filtering options:",USERCOLOR_DEFAULT);
        for (DWORD i=0;MapFilterOptions[i].szName!=NULL;i++) 
        {
            WriteChatf("%s%s: %s",MapFilterOptions[i].szName,(MapFilterOptions[i].bIsToggle)?"":" #",MapFilterOptions[i].szHelpString);
        }
        WriteChatColor("'option' color [r g b]: Set display color for 'option' (Omit to reset to default)",USERCOLOR_DEFAULT);
        return 0;
    } 

    // Set option
    for (DWORD i=0;MapFilterOptions[i].szName!=NULL;i++) 
    {
        if (!stricmp(argv[1],MapFilterOptions[i].szName)) 
        {
            if (argc>=3 && !stricmp(argv[2],"color")) 
            {
                if (MapFilterOptions[i].DefaultColor == -1) 
                {
                    WriteChatf("Option '%s' does not have a color.",MapFilterOptions[i].szName);
                } 
                else 
                {
                    DWORD R,G,B;
                    if (argc<6) 
                    {
                        MapFilterOptions[i].Color = MapFilterOptions[i].DefaultColor;
                    } 
                    else 
                    {
                        R=atoi(argv[3]);
                        G=atoi(argv[4]);
                        B=atoi(argv[5]);
                        if (R>255) R=255;
                        if (G>255) G=255;
                        if (B>255) B=255;
                        MapFilterOptions[i].Color = R*0x10000 + G*0x100 + B;
                    }
                    WriteChatf("Option '%s' color set to: %d %d %d",MapFilterOptions[i].szName,R,G,B);

                    //itoa(MapFilterOptions[i].Color & 0xFFFFFF,szBuffer,10);
                    char szBuffer[128];
                    sprintf(szBuffer,"%s Color",MapFilterOptions[i].szName);
                    pISInterface->SetSettingi("ISXEQMap.XML","Map Filters",szBuffer,MapFilterOptions[i].Color & 0xFFFFFF);
                    pISInterface->SaveSettings("ISXEQMap.XML");

                    MapFilterOptions[i].Color |= 0xFF000000;
                }
            } 
            else 
            {
                MapFilterSetting(i,2,argc,argv);
            }
            if (MapFilterOptions[i].RegenerateOnChange)
            {
                MapClear();
                MapGenerate();
            }
            return 0;
        }
    }

    WriteChatf("Usage: %s <option>|help",argv[0]);
    return 0;
}
int CMD_MapHide(int argc, char *argv[])
{
    if (argc<2)
    {
        WriteChatf("Syntax: %s <spawnfilter>|reset",argv[0]);
        return 0;
    };
    if (!stricmp(argv[1],"reset"))
    {
        MapClear();
        MapGenerate();
        WriteChatColor("Map spawns regenerated",USERCOLOR_DEFAULT);
        return 0;
    }
    if (PCHARINFO pCharInfo=GetCharInfo())
    {
        SEARCHSPAWN ssHide;
        ClearSearchSpawn(&ssHide);
        ParseSearchSpawn(1,argc,argv,ssHide);
        WriteChatf("%d mapped spawns hidden",MapHide(ssHide));
    }
    return 0;
}
int CMD_MapShow(int argc, char *argv[])
{
    if (argc<2)
    {
        WriteChatf("Syntax: %s <spawnfilter>|reset",argv[0]);
        return 0;
    };
    if (!stricmp(argv[1],"reset"))
    {
        MapClear();
        MapGenerate();
        WriteChatf("Map spawns regenerated");
        return 0;
    }
    if (PCHARINFO pCharInfo=GetCharInfo())
    {
        SEARCHSPAWN ssShow;
        ClearSearchSpawn(&ssShow);
        ParseSearchSpawn(1,argc,argv,ssShow);
        WriteChatf("%d previously hidden spawns shown",MapShow(ssShow));
    }
    return 0;
}
int CMD_MapHighlight(int argc, char *argv[])
{
    if (argc<2)
    {
        WriteChatf("Syntax: /highlight reset|<spawnfilter>|color <#> <#> <#>");
        return 0;
    };

    if (!stricmp(argv[1],"color"))
    {
        if (argc<5)
        {
            WriteChatf("Highlight color: %d %d %d",(HighlightColor&0x00FF0000)>>16,(HighlightColor&0x0000FF00)>>8,(HighlightColor&0x000000FF));
            return 0;
        }
        unsigned char R=atoi(argv[2]);
        unsigned char G=atoi(argv[3]);
        unsigned char B=atoi(argv[4]);
        HighlightColor=0xFF000000 | (R << 16) | (G << 8) | (B);
        WriteChatf("Highlight color: %d %d %d",R,G,B);
        return 0;
    }
    else if (!stricmp(argv[1],"reset"))
    {
        MapHighlight(0);
        WriteChatColor("Highlighting reset",USERCOLOR_DEFAULT);
        return 0;
    }

    if (PCHARINFO pCharInfo=GetCharInfo())
    {
        SEARCHSPAWN ssHighlight;
        ClearSearchSpawn(&ssHighlight);
        ParseSearchSpawn(1,argc,argv,ssHighlight);
        WriteChatf("%d mapped spawns highlighted",MapHighlight(&ssHighlight));
    }
    return 0;
}
int CMD_MapNames(int argc, char *argv[])
{
    if (argc<2)
    {
        WriteChatf("Normal naming string: %s",MapNameString);
        WriteChatf("Target naming string: %s",MapTargetNameString);
        return 0;
    }
    if (!stricmp(argv[1],"target"))
    {
        if (argc==3 && !stricmp(argv[2],"reset"))
            strcpy(MapTargetNameString,"%N");
        else
            pISInterface->GetArgs(2,argc,argv,MapTargetNameString,sizeof(MapTargetNameString));
        WriteChatf("Target naming string: %s",MapTargetNameString);
        pISInterface->SetSetting("ISXEQMap.XML","Naming Schemes","Target",MapTargetNameString);
        pISInterface->SaveSettings("ISXEQMap.XML");
        MapClear();
        MapGenerate();
    }
    else if (!stricmp(argv[1],"normal"))
    {
        if (argc==3 && !stricmp(argv[2],"reset"))
            strcpy(MapNameString,"%N");
        else
            pISInterface->GetArgs(2,argc,argv,MapNameString,sizeof(MapNameString));
        WriteChatf("Normal naming string: %s",MapNameString);
        pISInterface->SetSetting("ISXEQMap.XML","Naming Schemes","Normal",MapNameString);
        pISInterface->SaveSettings("ISXEQMap.XML");
        MapClear();
        MapGenerate();
    }
    else
    {
        WriteChatf("Syntax: %s target|normal <value>|reset",argv[0]);
    }
    return 0;
}
extern PCHAR DescribeCombo(DWORD Combo);
extern DWORD ParseCombo(PCHAR Combo);
int CMD_MapClick(int argc, char *argv[])
{
    if (argc<2)
    {
        WriteChatf("Syntax: %s list|[key[+key[...]]] clear|<command>");
        return 0;
    }

    if (!stricmp(argv[1],"list"))
    {
        int Count=0;
        for (int i=1 ; i < 16 ; i++)
        {
            if (MapSpecialClickString[i][0])
            {
                WriteChatf("%s: %s",DescribeCombo(i),MapSpecialClickString[i]);
                Count++;
            }
        }
        WriteChatf("%d special right-click commands",Count);
        return 0;
    }

    DWORD Combo=ParseCombo(argv[1]);
    if (!Combo)
    {
        WriteChatf("Invalid combo '%s'",argv[1]);
        return 0;
    }

    if (argc<3)
    {
        WriteChatf("%s: %s",DescribeCombo(Combo),MapSpecialClickString[Combo]);
        return 0;
    }

    char szBuffer[2048];
    sprintf(szBuffer,"KeyCombo%d",Combo);
    if (!stricmp(argv[2],"clear"))
    {
        MapSpecialClickString[Combo][0]=0;

        pISInterface->SetSetting("ISXEQMap.XML","Right Click",szBuffer,MapSpecialClickString[Combo]);
        pISInterface->SaveSettings("ISXEQMap.XML");
        WriteChatf("%s cleared",DescribeCombo(Combo));
        return 0;
    }

    pISInterface->GetArgs(2,argc,argv,MapSpecialClickString[Combo], MAX_STRING);
    pISInterface->SetSetting("ISXEQMap.XML","Right Click",szBuffer,MapSpecialClickString[Combo]);
    pISInterface->SaveSettings("ISXEQMap.XML");
    WriteChatf("%s: %s",DescribeCombo(Combo),MapSpecialClickString[Combo]);
    return 0;
}
