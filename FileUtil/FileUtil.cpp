#include "FileUtil.hpp"

bool SearchFilePath(const wchar_t* filename, std::wstring& result)
{
	if (filename == nullptr)
	{
		LOG_CRITICAL("filenameが見つかりません");
		return false;
	}
	if (wcscmp(filename, L"") == 0 || wcscmp(filename, L"") == 0)
	{
		LOG_CRITICAL("filenameが空文字列です");
		return false;
	}
	wchar_t exePath[520] = {};
	GetModuleFileNameW(nullptr, exePath, 520);
	exePath[519] = L'\0';	// null 終端化
	PathRemoveFileSpecW(exePath);

	wchar_t dstPath[520] = {};

	wcscpy_s(dstPath, filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath, L"..\\%s",filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath, L"..\\..\\%s",filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath,L"\\res\\%s",filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath, L"%s\\%s", exePath, filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath, L"%s\\..\\%s", exePath, filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath, L"%s\\..\\..\\%s", exePath, filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}

	swprintf_s(dstPath, L"%s\\res\\%s", exePath, filename);
	if (PathFileExistsW(dstPath) == TRUE)
	{
		result = dstPath;
		return true;
	}
	return false;
}
