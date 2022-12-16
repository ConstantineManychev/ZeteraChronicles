#import "HelperUtils.h"
#import "GCSWrapper.h"
#import "Managers/Players/PlayerProfile.h"
#include "Managers/Data/DataManager.h"
#include "BGameManager.h"
#include "GameDirector.h"

_USEB

#if ( CC_TARGET_PLATFORM ==  CC_PLATFORM_IOS )

std::string HelperUtils::stringToUpper(const std::string &aStr, const unsigned aStartIndex,const unsigned aEndIndex, const std::string& aLoc)
{
    std::string result = aStr;
    NSString* strUpper = [[NSString stringWithCString:aStr.c_str() encoding:NSUTF8StringEncoding] uppercaseString];
    NSString* str = [NSString stringWithCString:aStr.c_str() encoding:NSUTF8StringEncoding] ;
    
    if (strUpper && str && aStartIndex < aEndIndex && strUpper.length >= aEndIndex)
    {
        NSRange range = NSMakeRange(aStartIndex,aEndIndex);
        result = [[str stringByReplacingCharactersInRange:range withString: [strUpper substringWithRange:range]] UTF8String];
    }
    
    return result;
}

void HelperUtils::shareObject(eShareDataType aType, const std::string& aText, const std::string& aImgUri)
{
    NSString* textShare = [NSString stringWithCString:aText.c_str() encoding:NSUTF8StringEncoding];
    NSMutableArray* filesToShare = [NSMutableArray arrayWithObjects:textShare, nil];
    
    if (aType == eShareDataType::IMAGE)
    {
        NSString* imgPath = [NSString stringWithCString:aImgUri.c_str() encoding:NSUTF8StringEncoding];
        NSURL* imgUrl = [[NSURL alloc] initFileURLWithPath:imgPath];
        
        NSData * imageData = [[NSData alloc] initWithContentsOfURL:imgUrl];
		
		if (imageData)
		{
			UIImage* image = [[UIImage alloc] initWithData:imageData];
        
			NSData* shareData = UIImagePNGRepresentation(image);
        
			[filesToShare addObject:shareData];
		}
    }
    
    UIWindow* window = [UIApplication sharedApplication].keyWindow;
    UIViewController* rootViewController = window.rootViewController;
    
    UIActivityViewController* activityViewController = [[UIActivityViewController alloc] initWithActivityItems:filesToShare applicationActivities:nil];
    if(activityViewController.popoverPresentationController){
        activityViewController.popoverPresentationController.sourceView = rootViewController.view;
        activityViewController.popoverPresentationController.sourceRect = CGRectMake(rootViewController.view.bounds.size.width, rootViewController.view.bounds.size.height, 0, 0);
    }
    [rootViewController presentViewController:activityViewController animated:YES completion:nil];
}

std::string HelperUtils::stringToLower(const std::string &aStr, const unsigned aStartIndex,const unsigned aEndIndex)
{
    std::string result = aStr;
    NSString* strUpper = [[NSString stringWithCString:aStr.c_str() encoding:NSUTF8StringEncoding] lowercaseString];
    NSString* str = [NSString stringWithCString:aStr.c_str() encoding:NSUTF8StringEncoding] ;
    
    if (strUpper && str && aStartIndex < aEndIndex && strUpper.length >= aEndIndex)
    {
        NSRange range = NSMakeRange(aStartIndex,aEndIndex);
        result = [[str stringByReplacingCharactersInRange:range withString: [strUpper substringWithRange:range]] UTF8String];
    }
    
    return result;
}

#endif

/*
std::string HelperUtils::getSupportPageURL()
{
    std::string url = GCSWrapper::getInstance()->getSupportURL();

    BValue progress;

    int coins = PLAYER->getCurrency(eCurrencyType::CASH);
    int gems = PLAYER->getCurrency(eCurrencyType::CRYSTALS);
    int level = PLAYER->getLevel();
    int exp = PLAYER->getExperience();
    int maxExp = 0;

    const auto nextLevelInfo = DM->getLevelInfoByNumber(level + 1);
    if (nextLevelInfo)
    {
        maxExp = nextLevelInfo->requiredExperience;
    }

    progress.initWithFormat("level=%d+Xp(%d+of+%d),+Coins+%d,+Gems+%d", level, exp, maxExp, coins, gems);

    std::string toAppend = "&" + progress.getString();

    url.append(toAppend);

    bool needToDeleteSpaces = true;

    while (needToDeleteSpaces)
    {
        auto pos = url.find(" ");

        if (pos == std::string::npos)
        {
            needToDeleteSpaces = false;
        }
        else
        {
            url.replace(pos, 1, "%20");
        }
    }

    int pos = url.find("https");

    if (pos == std::string::npos)
    {
        pos = url.find("http");

        if (pos != std::string::npos)
        {
            url.replace(pos, 4, "https");
        }
    }

    return url;
}

*/
