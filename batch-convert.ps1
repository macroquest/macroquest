$projects = @{
    'src\main\MQ2Main.vcxproj' = 'core';
    'src\eqlib\eqlib.vcxproj' = 'core';
    'src\imgui\imgui.vcxproj' = 'core/libraries';
    'src\login\login.vcxproj' = 'core/libraries';
    'src\routing\routing.vcxproj' = 'core/libraries';
    'contrib\zep\zep.vcxproj' = 'core/libraries';
    'src\loader\MacroQuest.vcxproj' = 'core/applications';
    'src\plugins\autobank\MQ2AutoBank.vcxproj' = 'core/plugins';
    'src\plugins\autologin\MQ2AutoLogin.vcxproj' = 'core/plugins';
    'src\plugins\bzsrch\MQ2Bzsrch.vcxproj' = 'core/plugins';
    'src\plugins\chat\MQ2Chat.vcxproj' = 'core/plugins';
    'src\plugins\chatwnd\MQ2ChatWnd.vcxproj' = 'core/plugins';
    'src\plugins\custombinds\MQ2CustomBinds.vcxproj' = 'core/plugins';
    'src\plugins\eqbugfix\MQ2EQBugFix.vcxproj' = 'core/plugins';
    'src\plugins\hud\MQ2HUD.vcxproj' = 'core/plugins';
    'src\plugins\itemdisplay\MQ2ItemDisplay.vcxproj' = 'core/plugins';
    'src\plugins\labels\MQ2Labels.vcxproj' = 'core/plugins';
    'src\plugins\lua\MQ2Lua.vcxproj' = 'core/plugins';
    'src\plugins\map\MQ2Map.vcxproj' = 'core/plugins';
    'src\plugins\pluginapi\pluginapi.vcxproj' = 'core/plugins';
    'src\plugins\targetinfo\MQ2TargetInfo.vcxproj' = 'core/plugins';
    'src\plugins\xtarinfo\MQ2XTarInfo.vcxproj' = 'core/plugins';
    'src\tests\Actors\Actors.vcxproj' = 'core/applications/tests';
    'src\tests\NamedPipeClient\NamedPipeClient.vcxproj' = 'core/applications/tests';
}

foreach ($proj in $projects.GetEnumerator()) {
    Write-Host "Converting $proj..."
    .\tools\conversions\Convert-VcxprojToCMake.ps1 -VcxprojPath $proj.Key -GenerateAnalysis -Force -SolutionFolder $proj.Value
}

Write-Host "Batch conversion complete"