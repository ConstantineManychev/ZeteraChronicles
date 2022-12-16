#include "Managers/Data/EncryptionFileManager.h"
/*
#include "aes256.h"
#include "base/base64.h"
#include "base/ZipUtils.h"
#include "zlib.h"
#include "md5.h"
*/

#include "BCommon.h" // TODO NEED FOR FileUtils
#include "BCommonHelper.h"


USING_NS_CC;

EncryptionFileManager::EncryptionFileManager() 
: cAesBlockSize( 32 )
, mIsEncrypted( false )
, mEncExt( "bg" )
{

}

EncryptionFileManager::~EncryptionFileManager()
{

}

void EncryptionFileManager::init()
{
	mEncriptionFiles.clear();

	addEncFilePath( "data/main_config.json", "gUkXp2s5v8y/B?D(G+KbPeShVmYq3t6w" );
	addEncFilePath("data/debug_config.json", "VmYq3t6w9z$C&F)J@NcRfUjWnZr4u7x!");
}

void EncryptionFileManager::addEncFilePath( const std::string& aFilePath, const std::string& aAesKey )
{

#ifdef COCOS2D_DEBUG
	if ( mEncriptionFiles.find(aFilePath) != mEncriptionFiles.end() )
	{
		log("EncryptionFileManager::addEncFilePath filePath[%s] already exist", aFilePath.c_str() );
	}
#endif
	mEncriptionFiles[aFilePath] = aAesKey;
}

std::string EncryptionFileManager::getAesKeyForFilePath( const std::string& filePath )
{
	std::string result;

#ifdef COCOS2D_DEBUG
	if ( mEncriptionFiles.find( filePath ) == mEncriptionFiles.end() )
	{
		log("EncryptionFileManager::getAesKeyForFilePath key for filePath[%s] not exist", filePath.c_str());
	}
#endif

	result = mEncriptionFiles[filePath];
	return result;
}

void EncryptionFileManager::encryptFiles()
{
	for ( auto it = mEncriptionFiles.begin(); it != mEncriptionFiles.end(); ++it )
	{
		FileUtils* fu = FileUtils::getInstance();
		std::string filePath = (*it).first;
		std::string fileFullPath = fu->fullPathForFilename( filePath );

		if ( !( fileFullPath.empty() ) )
		{
			std::string eFilePath = checkExtension( fileFullPath, true );

			std::string fileEntry = fu->getStringFromFile( fileFullPath );
			std::string encFileEntry = BCommonHelper::aesEncrypt( fileEntry, getAesKeyForFilePath(filePath) );

			if ( !saveStringToFile( eFilePath, encFileEntry ) )
			{
				log( "[EncryptionFileManager::encryptFiles] Error Create encrypted file: \'%s\' ", ( eFilePath ).c_str() );
			}
		}
	}
}

bool EncryptionFileManager::saveStringToFile(const std::string& absolutePath, const std::string& data)
{
	bool result = false;
	FILE* f = fopen(absolutePath.c_str(), "w");

	if (f)
	{
		int size = strlen(data.c_str());
		fwrite(data.c_str(), sizeof(char) * size, 1, f);

		fclose(f);
		result = true;
	}
	
	return result;
}

bool EncryptionFileManager::isEncrypted()
{
	return mIsEncrypted;
}
void EncryptionFileManager::setIsEncrypted( bool isEncrypted )
{
	mIsEncrypted = isEncrypted;
}
std::string EncryptionFileManager::checkExtension( const std::string& filePath, bool force )
{
	std::string result = filePath;
	
	size_t i = result.find_last_of(".");

	std::string clearName;
	std::string clearExt;

	if ( i != std::string::npos )
	{
		clearName = result.substr( 0, i );
		clearExt = result.substr( i+1, result.size() - i - 1 );

		if ( mIsEncrypted || force )
			result = clearName + "." + mEncExt;
	}
	else
	{
		if ( mIsEncrypted || force )
			result += mEncExt;
	}

	return result;
}
std::string EncryptionFileManager::getFileString( const std::string& filePath )
{
	std::string result;
	std::string path = checkExtension( filePath );
	std::string fileEntry = FileUtils::getInstance()->getStringFromFile( path );
	

	if ( !fileEntry.empty() )
	{
		if ( mIsEncrypted )
		{
			result = BCommonHelper::aesDecrypt(  fileEntry, getAesKeyForFilePath(filePath) );
		}
		else
		{
			result = fileEntry;
		}
	}
	else
	{
		;//log( "[EncryptionFileManager::getFileString] Can't open file \'%s\'", path.c_str() );
	}
	return result;
}
