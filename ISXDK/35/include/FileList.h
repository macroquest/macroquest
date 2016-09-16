#pragma once
struct _FileListEntry
{
	char Filename[512];
	char FilenameOnly[128];
	FILETIME ftCreationTime;
	FILETIME ftLastWriteTime;
	FILETIME ftLastAccessTime;
	unsigned int FileSize;
};

class CFileList
{
public:
	CFileList() 
	{
		nFiles=0;
	}
	~CFileList()
	{
		List.Cleanup();
	}

	void AddFile(LPWIN32_FIND_DATA pFile, char *Path)
	{
		_FileListEntry *pNew  = new _FileListEntry;
		sprintf(pNew->Filename,"%s%s",Path,pFile->cFileName);
		strcpy(pNew->FilenameOnly,pFile->cFileName);
		pNew->ftCreationTime=pFile->ftCreationTime;
		pNew->ftLastAccessTime=pFile->ftLastAccessTime;
		pNew->ftLastWriteTime=pFile->ftLastWriteTime;
		pNew->FileSize=pFile->nFileSizeLow;
		List+=pNew;
		nFiles++;
	}
	char *GetPath(char *Wildcard)
	{
		static char Path[512];
		if (char *pSlash=strrchr(Wildcard,'\\'))
		{
			strcpy(Path,Wildcard);
			Path[(pSlash-Wildcard)+1]=0;
		}
		else
			Path[0]=0;
		return Path;
	}
	unsigned int EnumDirectories(char *Wildcard)
	{
		WIN32_FIND_DATA file;
		HANDLE hSearch=FindFirstFile(Wildcard,&file);
		if (hSearch==INVALID_HANDLE_VALUE)
			return 0;
		char *Path=GetPath(Wildcard);
		do
		{
			if (_stricmp(file.cFileName,".") && _stricmp(file.cFileName,".."))
			if (file.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
				AddFile(&file,Path);
		} while (FindNextFile(hSearch,&file));

		FindClose(hSearch);
		return nFiles;
	}
	unsigned int EnumFiles(char *Wildcard)
	{
		WIN32_FIND_DATA file;
		HANDLE hSearch=FindFirstFile(Wildcard,&file);
		if (hSearch==INVALID_HANDLE_VALUE)
			return 0;
		char *Path=GetPath(Wildcard);
		do
		{
			if (!(file.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
				AddFile(&file,Path);
		} while (FindNextFile(hSearch,&file));

		FindClose(hSearch);
		return nFiles;
	}
	unsigned int EnumFilesAfter(FILETIME &filetime, char *Wildcard)
	{
		WIN32_FIND_DATA file;
		HANDLE hSearch=FindFirstFile(Wildcard,&file);
		if (hSearch==INVALID_HANDLE_VALUE)
			return 0;
		char *Path=GetPath(Wildcard);
		do
		{
			if (!(file.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) && 
				CompareFileTime(&file.ftLastWriteTime,&filetime)>0)
			{
					AddFile(&file,Path);
			}
		} while (FindNextFile(hSearch,&file));

		FindClose(hSearch);
		return nFiles;
	}

	unsigned int nFiles;
	CIndex <_FileListEntry *> List;
};

struct _FileListEntryW
{
	wchar_t Filename[512];
	wchar_t FilenameOnly[128];
	FILETIME ftCreationTime;
	FILETIME ftLastWriteTime;
	FILETIME ftLastAccessTime;
	unsigned int FileSize;
};

class CFileListW
{
public:
	CFileListW() 
	{
		nFiles=0;
	}
	~CFileListW()
	{
		List.Cleanup();
	}

	void Clear()
	{
		List.Cleanup();
		nFiles=0;
	}

	void AddFile(PWIN32_FIND_DATAW pFile, wchar_t *Path)
	{
		_FileListEntryW *pNew  = new _FileListEntryW;
		_snwprintf(pNew->Filename,512,L"%ls%ls",Path,pFile->cFileName);
		wcsncpy(pNew->FilenameOnly,pFile->cFileName,sizeof(pNew->FilenameOnly)/sizeof(pNew->FilenameOnly[0]));
		pNew->ftCreationTime=pFile->ftCreationTime;
		pNew->ftLastAccessTime=pFile->ftLastAccessTime;
		pNew->ftLastWriteTime=pFile->ftLastWriteTime;
		pNew->FileSize=pFile->nFileSizeLow;
		List+=pNew;
		nFiles++;
	}
	inline wchar_t *ConvertSlashes(wchar_t *text)
	{
		wchar_t *temp=text;
		while(wchar_t *pSlash=wcschr(temp,'\\'))
		{
			*pSlash='/';
			temp=&pSlash[1];
		}
		return text;
	}
	wchar_t *GetPath(const wchar_t *Wildcard)
	{
		static wchar_t Path[512];
		wchar_t temp[512];
		wcsncpy(temp,Wildcard,512);
		temp[511]=0;

		wchar_t *pLastSlash=wcsrchr(temp,'\\');
		if (pLastSlash)
		{
			wchar_t *pOtherSlash=wcsrchr(pLastSlash,'/');
			if (pOtherSlash && pOtherSlash>pLastSlash)
				pLastSlash=pOtherSlash;
		}
		else
			pLastSlash=wcsrchr(temp,'/');
		if (wchar_t *pSlash=pLastSlash)
		{
			wcsncpy(Path,temp,sizeof(Path)/sizeof(Path[0]));
			Path[(pSlash-temp)+1]=0;
			ConvertSlashes(Path);
		}
		else
			Path[0]=0;
		return Path;
	}
	unsigned int EnumDirectories(const wchar_t *Wildcard)
	{
		WIN32_FIND_DATAW file;
		HANDLE hSearch=FindFirstFileW(Wildcard,&file);
		if (hSearch==INVALID_HANDLE_VALUE)
			return 0;
		wchar_t *Path=GetPath(Wildcard);
		do
		{
			if (wcsicmp(file.cFileName,L".") && wcsicmp(file.cFileName,L".."))
			if (file.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
				AddFile(&file,Path);
		} while (FindNextFileW(hSearch,&file));

		FindClose(hSearch);
		return nFiles;
	}
	unsigned int EnumFiles(const wchar_t *Wildcard)
	{
		WIN32_FIND_DATAW file;
		HANDLE hSearch=FindFirstFileW(Wildcard,&file);
		if (hSearch==INVALID_HANDLE_VALUE)
			return 0;
		wchar_t *Path=GetPath(Wildcard);
		do
		{
			if (!(file.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
				AddFile(&file,Path);
		} while (FindNextFileW(hSearch,&file));

		FindClose(hSearch);
		return nFiles;
	}
	unsigned int EnumFilesAfter(FILETIME &filetime, const wchar_t *Wildcard)
	{
		WIN32_FIND_DATAW file;
		HANDLE hSearch=FindFirstFileW(Wildcard,&file);
		if (hSearch==INVALID_HANDLE_VALUE)
			return 0;
		wchar_t *Path=GetPath(Wildcard);
		do
		{
			if (!(file.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) && 
				CompareFileTime(&file.ftLastWriteTime,&filetime)>0)
			{
					AddFile(&file,Path);
			}
		} while (FindNextFileW(hSearch,&file));

		FindClose(hSearch);
		return nFiles;
	}

	unsigned int nFiles;
	CIndex <_FileListEntryW *> List;
};
