# Changelog

All noticable changes to this project will be documented in this file.

## [Unreleased]

## [2.9.2] - 2019-03-18 by EqMule
### Changed
- Added support for more server is full error messages.

## [2.9.1] - 2018-12-12 by EqMule
### Fixed
- `NotifyOnServerUp` will now only trigger the first time it detects the server is up after being down or locked.

## [2.9.0] - 2018-12-11 by EqMule
### Added 
- Added `NotifyOnServerUp` to the mq2autologin inifile in the `[Settings]` section.
  If you set it to `NotifyOnServerUP=1` it will BEEP when server is up.
  If you set it to `NotifyOnServerUP=2` it will also email you if you have the MQ2GMail plugin loaded and correctly configured.

### Fixed
- Made MQ2AutoLogin not try to join a locked/down server.

## [2.8.1] - 2018-05-21 by EqMule
### Added
- Added ability to track character class and level through MQ2AutoLogin using MacroQuest2.exe

## [2.8.0] - 2018-03-11 by SwiftyMUSE
### Added
- Added global hotkey processing by @SwiftyMUSE

## [2.7.0] - 2016-10-04 by EqMule
### Added
- Added a new flag to make sure we have tried to get credentials.
- And other changes

## [2.6.0] - 2016-08-21 by Derple
### Added
- Added a new flag which disables autologin after the first successful login. It can be re-enabled by pressing HOME.

## [2.5.0] - 2016-07-29 by EqMule
### Changed
- Moved processing into its own detour, removed waitforinputidle and all arbitrary Sleeps.

## [2.4.0] - 2016-07-22 by EqMule
### Added
- Added support for emulators

## [2.3.0] - 2016-07-22 by EqMule
### Added
- Added string safety.

## [2.2.0] - 2016-06-29 by EqMule & Derple
### Fixed
- Made all WaitForInputIdle 60 seconds to prevent crashes
- Added an extra crash check

## [2.1.0] - 2016-06-27 by EqMule
### Added
- Added Encryption to the plugin and support for MacroQuest2.exe profiles.

## [2.0.0] - 2016-06-16 by EqMule
### Added
- Added Version Support
- Added a feature to login your char if you load/reload at char select. This setting is called 
  `LoginOnReloadAtCharSelect=1` and should go under `[Settings]` if you want to use it.

### Fixed
- Updated to not crash on /unload

## [1.18.0] 2015-07-11 by EqMule
### Changed
- Updated for lockjaw server

## [1.17.0] 2015-05-23 by EqMule
### Changed
- Updated for ragefire server

### Fixed
- Made some bug fixes

## [1.16.0] 2013-10-09 by ieatacid
### Changed
- Added 'test' to server list, per request

## [1.15.0] 2013-10-04 by EqMule
### Changed
- Updated for latest patch

### Fixed
- Had to change the MAX_WINDOWS or we would get caught in a loop

## [1.14.0] 2012-11-01
### Changed
- Added vox and trakanon servers

## [1.13.0] 2012-10-20
### Added
- Added ability to check for active characters and login offline character
- Removed instant camp stuff

## [1.12.0] 2012-09-01
### Fixed
- Doubled Sleep durations to stop crashes

## [1.11.0] 2011-12-01
### Changed
- Updated for VoA expansion release

## [1.10.0] 2011-02-15
### Changed
- Added new server names (thanks, htw)

## [1.9.0] 2010-10-24
### Fixed
- Fixed offset patterns that were broken with House of Thule expansion release

## [1.8.0] 2010-06-22
### Changed
- Adjusted for server merges

## [1.7.0] 2009-11-25
### Fixed
- Fixed issue with a blank character name making the login process stop at character select

## [1.6.0] 2009-11-21
### Added
- Now supports using station names rather than sessions (this is helpful if you use WinEQ2 profiles)

## [1.5.0] 2009-11-18
### Added
- The plugin now clicks through the order expansion screen

## [1.4.0] 2009-11-17
### Added
- The plugin will now click through the seizure warning screen

## [1.3.0] 2009-09-08
### Changed
- Made some adjustments that speed up logging in
- Debug logging now adds a time stamp

## [1.2.0] 2009-09-06
### Changed
- The session count is retrieved using the process list rather than enumerating through windows
- If debugging is enabled, the output now goes to a text file at "c:/MQ2AutoLogin_dbg.txt". The file path can be changed at the top of the .cpp file
- If server name isn't specified in the ini file it will stop at the server-select screen
- If a character name isn't specified in the ini file it will stop at the character-select screen

### Fixed
- Fixed a bug where two threads were being created at start-up

## [1.1.0] 2009-09-06
### Added
- Added ini option for setting a different ini file path, e.g. (in Settings) "IniLocation=x:\mq2"
- Integrated MQ2SwitchChar

## [1.0.0] 2009-08-31
- Initial release