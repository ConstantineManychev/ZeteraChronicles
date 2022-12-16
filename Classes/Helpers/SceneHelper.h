#ifndef SceneHelper_h
#define SceneHelper_h

#include "BCommonDefines.h"
#include "BValue.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "BGDStructs.h"
#include "Types/DataTypes.h"

_BSTART

#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

#define MAX_PLAYER_POS 9999

enum class eAppDelegateResolution;
class SceneHelper {
public:

	static BValueVector mTestingLogs;

	static void updateRemainingTimeToTarget( Label* aTimeLabel, long aTargetTime, const std::string& aScheduleTag, std::function< void() > aFunc = nullptr );
	
    static unsigned long getCurrentTime();

    static uint64_t getCurrentTimeInMilliseconds();
    
	static std::map< eTimeFormatType, int > getRemainingTimeToTargetInSpecialFormat( unsigned long aTargetTime );
	static std::map< eTimeFormatType, int > getTimeInSpecialFormat( long aTargetTime );

	static void setTimeToLabelInSpecialFormat( Label* aTimeLabel, long aTargetTime );
	static void setTimeToLabeInSpecialMarathonFormat( Label* aTimeLabel, long aTargetTime );
	static void setTimeToLabelInSpecialMarathonFormatHM(std::string stringID, Label* aTimeLabel, long aTargetTime);
	static void setTimeToLabelInSimpleFormat(Label* aTimeLabel, long aTargetTime, int borderDay = -1);

	static unsigned long convertStringToULong(const std::string& aConvertedString);

	static Node* createBlurredTexture(const std::string& aTextureResID, Size& aBluredTextureSize, Vec2& aBluredTexturePos, float aBlurStrength);

	static unsigned long getGameTime();
	static void switchMainScreenBack(const std::string& aCalledFrom, BValueMap aParams = BValueMap());
	static std::tm getGameDate();

	static std::string getStrFromAppDelegateResolution( eAppDelegateResolution aAppDelegateResolution );

	static tm* getTimeStructByTimeInSeconds( time_t aTime );

	static time_t getMidnightTimeForDayByTimeInSeconds( time_t aTime );
	static time_t calculateMidnightTime(time_t aTime);

	static void setImageFromTexturePack(Node* aNode, const std::string& aTexturePack, const std::string& aTextureId, bool aIsScaleToFrameSize = false);
	static void setImageFromTexturePackAndScale(Node* aNode, Node* aBox, const std::string& aTexturePack, const std::string& aTextureId);
	static void setImage(Node* aNode, const std::string& aPath, bool aIsScaleToFrameSize = false);
	static void loadTextureAsync(const std::string& aPath, std::function< void(std::string) > aFunc = nullptr);
	static void loadTextureAsyncCDN(const std::string& aPath, std::function< void(std::string) > aFunc = nullptr);
	static void launchAllActionTracks(Node* aTarget);
	static void stopAllActionTracks(Node* aTarget);

	// NEW

	static void addLog(const BValue& aLog);
	static void clearLogs();
	static void saveLogs();
	static void flushLogs(const BValue& aLog, std::string aNameFile = "logs");
	static void clearLogs(std::string aNameFile = "logs");

	static Texture2D* transformAvatarAnimationToSprite(const std::string& aClipping, const std::string aAvatar, Node* aPanel);
    static RenderTexture* renderTextureFromNode(Node* aSource, bool aForcedRender = false);
	//@param aQuality - quality of the picture 0 - 100
	static bool saveRenderTextureAsWebp(RenderTexture* aRenderTexture, const std::string & aFullPath, float aQuality = 100.0f, std::function<void()> aSaveCallback = nullptr);
	//@param aQuality - quality of the picture 0 - 100	
	static bool saveRenderTextureAsWebp(RenderTexture* aRenderTexture, const std::string & aFullPath, const Size & aSize, const float aScale, float aQuality = 100.0f);
	static bool saveRenderTextureAsPNG(RenderTexture* aRenderTexture, const std::string& aFullPath, std::function<void()> aSaveCallback);
	static bool savePlayerAvatarToFile(Node* aCharacter);
    static bool saveSharePictureToFile(const sLookMetaData& aItemMetaData, eImageFormat aImageFormate = eImageFormat::WEBP, std::function<void()> aSaveCallback = nullptr);
	static void useFBIconInsteadAvatar(Node* aPanel, const std::string& aClipping, const std::string aAvatar, const std::string aId, bool aIsUseIcon = true,const std::string& aKey = "small_icon");
	static bool useFBIcon(Node* aPanel, const std::string& aFBId,const std::string& aKey = "small_icon");
	static Texture2D* updateAvatarPlayer(Node* aPanel, const std::string& aClipping, const std::string aAvatar, const std::string aId, bool aIsIcon,const std::string& aKey = "small_icon");

	static sBGDNodeInfo getTemplateInfo(const std::vector<std::string>& aPaths, const std::string& aName);
	static sBGDNodeInfo getTemplateInfo(const std::string& aPaths, const std::string& aName);

	static Node* createTemplate(const std::vector<std::string>& aPaths, const std::string& aName, Node* aParent);
	static Node* createTemplate(const std::string& aPaths, const std::string& aName, Node* aParent);

	static Node* createNodeFromTemplateInfo(const sBGDNodeInfo& aPaths, Node* aParent);

	static std::string constructItemName( const std::string& aItemId );

	static void setPlayerPosWithSpecialCheck(Label* aLabel, std::string aPlayerPos, Node* aBorderNode = nullptr);

	static std::string getSaveIdFromItemID(const std::string& aItemId);

	static void loadBrandIconToSlot(Sprite* aBrandCell, const std::string& aTexturePack, const std::string& aTextureId);

    static bool isCircleNodeContainsCoord(Node* aCircleNode, Vec2 aCoord);

	static bool setNordcurrentIDAvatar(Sprite* aAvatarNode, const std::string& aAvatarData, bool aIsNewUpdate = false);
	static Sprite* createSpriteWithParams(BValueMap& aParams, Node* aParent = nullptr);
	static bool createImageFromDataAndSaveToFile(const std::string& aAvatarData, const std::string& aFilePath);
};

_BEND

#endif /* SceneHelper_h */
