#ifndef EncryptionFileManager_H
#define EncryptionFileManager_H

#include "cocos2d.h"
#include "BCommonDefines.h"
#include <map>
#include <string>

NS_CC_BEGIN
	class EncryptionFileManager
	{
		//< filePath, aes_key_id >
		std::map< std::string, std::string > mEncriptionFiles;
		
		std::string mEncExt;
		const int cAesBlockSize;
		bool mIsEncrypted;
		
		std::string getAesKeyForFilePath( const std::string& aFilePath );

		std::string checkExtension( const std::string& filePath, bool force = false );

		bool saveStringToFile(const std::string& aAbsolutePath, const std::string& aData);

		void addEncFilePath(const std::string& aFilePath, const std::string& aAesKey);
	public:

		void init();
	
		bool isEncrypted();
		void setIsEncrypted( bool aIsEncrypted );

		EncryptionFileManager();
		virtual ~EncryptionFileManager();

		void encryptFiles();
		std::string getFileString( const std::string& aFilePath );		
	};
NS_CC_END

#endif