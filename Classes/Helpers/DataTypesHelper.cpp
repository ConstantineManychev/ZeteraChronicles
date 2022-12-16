#include "DataTypesHelper.h"
#include "Managers/GameDirector.h"
#include "Managers/ItemSystem/ItemSystem.h"
#include "Helpers/SceneHelper.h"
#include "Managers/Data/DataManager.h"
#include <iomanip>
#include <locale>

#include "BCommon.h"
#include "BGameManager.h"
#include "Managers/Social/LeaderboardsManager.h"
#include "Helpers/DataHelper.h"
#include "Components/DataStorageComponent.h"
#include "Views/SimpleViews/DesignerView/Components/ColorPickerIconController.h"

_USEB

DataTypesHelper::DataTypesHelper()
{
}
DataTypesHelper::~DataTypesHelper()
{
}
eAnimAreaType DataTypesHelper::getAnimAreaTypeFromStr(const std::string& aStr)
{
	eAnimAreaType result = eAnimAreaType::FULL;

	if ( aStr == "FULL" )
	{
		result = eAnimAreaType::FULL;
	}
	else if ( aStr == "FACE" )
	{
		result = eAnimAreaType::FACE;
	}
	else if ( aStr == "BODY" )
	{
		result = eAnimAreaType::BODY;
	}
	else if ( aStr == "LEGS" )
	{
		result = eAnimAreaType::LEGS;
	}

	return result;
}
std::string DataTypesHelper::getStrFromAnimAreaType(eAnimAreaType aType)
{
	std::string result = "FULL";

	switch ( aType ) {
		case eAnimAreaType::FULL:
			result = "FULL";
			break;
		case eAnimAreaType::FACE:
			result = "FACE";
			break;
		case eAnimAreaType::BODY:
			result = "BODY";
			break;
		case eAnimAreaType::LEGS:
			result = "LEGS";
			break;
		default:
			break;
	}

	return result;
}
eLookType DataTypesHelper::getLookTypeFromStr(const std::string& aStr)
{
	eLookType result = eLookType::UNDEFINED;

	if ( aStr == "CUSTOMIZATION" )
	{
		result = eLookType::CUSTOMIZATION;
	}
	else if ( aStr == "HAIRSTYLE" )
	{
		result = eLookType::HAIRSTYLE;
	}
	else if ( aStr == "DRESS" )
	{
		result = eLookType::DRESS;
	}
	else if ( aStr == "TOP_A" )
	{
		result = eLookType::TOP_A;
	}
	else if ( aStr == "TOP_A_TUCKED" )
	{
		result = eLookType::TOP_A_TUCKED;
	}
	else if ( aStr == "TOP_B" )
	{
		result = eLookType::TOP_B;
	}
	else if ( aStr == "BOTTOM" )
	{
		result = eLookType::BOTTOM;
	}
	else if ( aStr == "SHOES" )
	{
		result = eLookType::SHOES;
	}
	else if ( aStr == "ACCESSORIES" )
	{
		result = eLookType::ACC_ALL;
	}
	else if ( aStr == "ACC_HATS" )
	{
		result = eLookType::ACC_HATS;
	}
	else if ( aStr == "ACC_GLASSES" )
	{
		result = eLookType::ACC_GLASSES;
	}
	else if ( aStr == "ACC_JEWELRY" )
	{
		result = eLookType::ACC_JEWELRY;
	}
	else if ( aStr == "ACC_RINGS" )
	{
		result = eLookType::ACC_RINGS;
	}
	else if ( aStr == "ACC_BELTS" )
	{
		result = eLookType::ACC_BELTS;
	}
	else if ( aStr == "ACC_GLOVES" )
	{
		result = eLookType::ACC_GLOVES;
	}
	else if ( aStr == "ACC_EARRINGS" )
	{
		result = eLookType::ACC_EARRINGS;
	}
	else if ( aStr == "ACC_HANDBAGS" )
	{
		result = eLookType::ACC_HANDBAGS;
	}
	else if ( aStr == "ACC_NECKLACE" )
	{
		result = eLookType::ACC_NECKLACE;
	}
	else if ( aStr == "ACC_BACKPACKS" )
	{
		result = eLookType::ACC_BACKPACKS;
	}
	else if ( aStr == "ACC_SCARVES" )
	{
		result = eLookType::ACC_SCARVES;
	}
	else if ( aStr == "ACC_BROOCH" )
	{
		result = eLookType::ACC_BROOCH;
	}
	else if ( aStr == "ACC_STOCKINGS" )
	{
		result = eLookType::ACC_STOCKINGS;
	}
	else if ( aStr == "MAKEUP_EYES" )
	{
		result = eLookType::MAKEUP_EYES;
	}
	else if ( aStr == "MAKEUP_LIPS" )
	{
		result = eLookType::MAKEUP_LIPS;
	}
	else if ( aStr == "BOOTS" )
	{
		result = eLookType::BOOTS;
	}
	else if ( aStr == "PERFUME" )
	{
		result = eLookType::PERFUME;
	}
	else if ( aStr == "FACE_GLITTER" )
	{
		result = eLookType::FACE_GLITTER;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookType(eLookType aType)
{
	std::string result;

	switch ( aType ) {
		case eLookType::UNDEFINED:
			result = "UNDEFINED";
			break;
		case eLookType::CUSTOMIZATION:
			result = "CUSTOMIZATION";
			break;
		case eLookType::HAIRSTYLE:
			result = "HAIRSTYLE";
			break;
		case eLookType::DRESS:
			result = "DRESS";
			break;
		case eLookType::TOP_A:
			result = "TOP_A";
			break;
		case eLookType::TOP_A_TUCKED:
			result = "TOP_A_TUCKED";
			break;
		case eLookType::TOP_B:
			result = "TOP_B";
			break;
		case eLookType::BOTTOM:
			result = "BOTTOM";
			break;
		case eLookType::SHOES:
			result = "SHOES";
			break;
		case eLookType::ACC_ALL:
			result = "ACCESSORIES";
			break;
		case eLookType::ACC_HATS:
			result = "ACC_HATS";
			break;
		case eLookType::ACC_GLASSES:
			result = "ACC_GLASSES";
			break;
		case eLookType::ACC_JEWELRY:
			result = "ACC_JEWELRY";
			break;
		case eLookType::ACC_RINGS:
			result = "ACC_RINGS";
			break;
		case eLookType::ACC_BELTS:
			result = "ACC_BELTS";
			break;
		case eLookType::ACC_GLOVES:
			result = "ACC_GLOVES";
			break;
		case eLookType::ACC_EARRINGS:
			result = "ACC_EARRINGS";
			break;
		case eLookType::ACC_HANDBAGS:
			result = "ACC_HANDBAGS";
			break;
		case eLookType::ACC_NECKLACE:
			result = "ACC_NECKLACE";
			break;
		case eLookType::ACC_BACKPACKS:
			result = "ACC_BACKPACKS";
			break;
		case eLookType::ACC_SCARVES:
			result = "ACC_SCARVES";
			break;
		case eLookType::ACC_BROOCH:
			result = "ACC_BROOCH";
			break;
		case eLookType::ACC_STOCKINGS:
			result = "ACC_STOCKINGS";
			break;
		case eLookType::MAKEUP_EYES:
			result = "MAKEUP_EYES";
			break;
		case eLookType::MAKEUP_LIPS:
			result = "MAKEUP_LIPS";
			break;
		case eLookType::BOOTS:
			result = "BOOTS";
			break;
		case eLookType::PERFUME:
			result = "PERFUME";
			break;
		case eLookType::FACE_GLITTER:
			result = "FACE_GLITTER";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

eLookCategory DataTypesHelper::getLookCategoryFromStr(const std::string& aStr)
{
	eLookCategory result = eLookCategory::UNDEFINED;

	if ( aStr == "HAIRSTYLE" )
	{
		result = eLookCategory::HAIRSTYLE;
	}
	else if ( aStr == "MAKEUP_EYES" )
	{
		result = eLookCategory::MAKEUP_EYES;
	}
	else if ( aStr == "MAKEUP_LIPS" )
	{
		result = eLookCategory::MAKEUP_LIPS;
	}
	else if ( aStr == "DRESS" )
	{
		result = eLookCategory::DRESS;
	}
	else if ( aStr == "TOP_A" )
	{
		result = eLookCategory::TOP_A;
	}
	else if ( aStr == "TOP_B" )
	{
		result = eLookCategory::TOP_B;
	}
	else if ( aStr == "BOTTOM" )
	{
		result = eLookCategory::BOTTOM;
	}
	else if ( aStr == "SHOES" )
	{
		result = eLookCategory::SHOES;
	}
	else if ( aStr == "ACCESSORIES" )
	{
		result = eLookCategory::ACCESSORIES;
	}

	return result;
}

std::string DataTypesHelper::getStrFromLookCategory(eLookCategory aType)
{
	std::string result;

	switch ( aType ) {
		case eLookCategory::ACCESSORIES:
			result = "ACCESSORIES";
			break;
		case eLookCategory::BOTTOM:
			result = "BOTTOM";
			break;
		case eLookCategory::DRESS:
			result = "DRESS";
			break;
		case eLookCategory::HAIRSTYLE:
			result = "HAIRSTYLE";
			break;
		case eLookCategory::MAKEUP_EYES:
			result = "MAKEUP_EYES";
			break;
		case eLookCategory::MAKEUP_LIPS:
			result = "MAKEUP_LIPS";
			break;
		case eLookCategory::SHOES:
			result = "SHOES";
			break;
		case eLookCategory::TOP_A:
			result = "TOP_A";
			break;
		case eLookCategory::TOP_B:
			result = "TOP_B";
			break;
		default:
			break;
	}

	return result;
}

eLookFilterColor DataTypesHelper::getLookFilterColorFromStr(const std::string& aStr)
{
	eLookFilterColor result = eLookFilterColor::UNDEFINED;

	if ( aStr == "BLACK" )
	{
		result = eLookFilterColor::BLACK;
	}
	else if ( aStr == "WHITE" )
	{
		result = eLookFilterColor::WHITE;
	}
	else if ( aStr == "RED" )
	{
		result = eLookFilterColor::RED;
	}
	else if ( aStr == "GRAY" )
	{
		result = eLookFilterColor::GRAY;
	}
	else if ( aStr == "YELLOW" )
	{
		result = eLookFilterColor::YELLOW;
	}
	else if ( aStr == "BLUE" )
	{
		result = eLookFilterColor::BLUE;
	}
	else if ( aStr == "PINK" )
	{
		result = eLookFilterColor::PINK;
	}
	else if ( aStr == "GREEN" )
	{
		result = eLookFilterColor::GREEN;
	}
	else if ( aStr == "BEIGE" )
	{
		result = eLookFilterColor::BEIGE;
	}
	else if ( aStr == "ORANGE" )
	{
		result = eLookFilterColor::ORANGE;
	}
	else if ( aStr == "PURPLE" )
	{
		result = eLookFilterColor::PURPLE;
	}
	else if ( aStr == "BROWN" )
	{
		result = eLookFilterColor::BROWN;
	}
	else if ( aStr == "TURQUOISE" )
	{
		result = eLookFilterColor::TURQUOISE;
	}
	else if ( aStr == "MULTICOLOR" )
	{
		result = eLookFilterColor::MULTICOLOR;
	}

	else if ( aStr == "END" )
	{
		result = eLookFilterColor::FILTER_END;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookFilterColor(eLookFilterColor aLookFilterColor)
{
	std::string result;

	switch ( aLookFilterColor )
	{
		case eLookFilterColor::BLACK:
			result = "BLACK";
			break;
		case eLookFilterColor::WHITE:
			result = "WHITE";
			break;
		case eLookFilterColor::RED:
			result = "RED";
			break;
		case eLookFilterColor::GRAY:
			result = "GRAY";
			break;
		case eLookFilterColor::YELLOW:
			result = "YELLOW";
			break;
		case eLookFilterColor::BLUE:
			result = "BLUE";
			break;
		case eLookFilterColor::PINK:
			result = "PINK";
			break;
		case eLookFilterColor::GREEN:
			result = "GREEN";
			break;
		case eLookFilterColor::BEIGE:
			result = "BEIGE";
			break;
		case eLookFilterColor::ORANGE:
			result = "ORANGE";
			break;
		case eLookFilterColor::PURPLE:
			result = "PURPLE";
			break;
		case eLookFilterColor::BROWN:
			result = "BROWN";
			break;
		case eLookFilterColor::TURQUOISE:
			result = "TURQUOISE";
			break;
		case eLookFilterColor::MULTICOLOR:
			result = "MULTICOLOR";
			break;
		default:
			result = "UNDEFINED";
			break;
	};

	return result;
}
eLookFilterFabric DataTypesHelper::getLookFilterFabricFromStr(const std::string& aStr)
{
	eLookFilterFabric result = eLookFilterFabric::UNDEFINED;

	if ( aStr == "DENIM" )
	{
		result = eLookFilterFabric::DENIM;
	}
	else if ( aStr == "LEATHER" )
	{
		result = eLookFilterFabric::LEATHER;
	}
	else if ( aStr == "SEQUIN" )
	{
		result = eLookFilterFabric::SEQUIN;
	}
	else if ( aStr == "COTTON" )
	{
		result = eLookFilterFabric::COTTON;
	}
	else if ( aStr == "SILK" )
	{
		result = eLookFilterFabric::SILK;
	}
	else if ( aStr == "SUEDE" )
	{
		result = eLookFilterFabric::SUEDE;
	}
	else if ( aStr == "WOOL" )
	{
		result = eLookFilterFabric::WOOL;
	}
	else if ( aStr == "SYNTHETIC" )
	{
		result = eLookFilterFabric::SYNTHETIC;
	}
	else if ( aStr == "FAUX_FUR" )
	{
		result = eLookFilterFabric::FAUX_FUR;
	}

	else if ( aStr == "END" )
	{
		result = eLookFilterFabric::FILTER_END;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookFilterFabric(eLookFilterFabric aLookFilterFabric)
{
	std::string result;

	switch ( aLookFilterFabric )
	{
		case eLookFilterFabric::DENIM:
			result = "DENIM";
			break;
		case eLookFilterFabric::LEATHER:
			result = "LEATHER";
			break;
		case eLookFilterFabric::SEQUIN:
			result = "SEQUIN";
			break;
		case eLookFilterFabric::COTTON:
			result = "COTTON";
			break;
		case eLookFilterFabric::SILK:
			result = "SILK";
			break;
		case eLookFilterFabric::SUEDE:
			result = "SUEDE";
			break;
		case eLookFilterFabric::WOOL:
			result = "WOOL";
			break;
		case eLookFilterFabric::SYNTHETIC:
			result = "SYNTHETIC";
			break;
		case eLookFilterFabric::FAUX_FUR:
			result = "FAUX_FUR";
			break;

		default:
			result = "UNDEFINED";
			break;
	};

	return result;
}
eLookFilterStyle DataTypesHelper::getLookFilterStyleFromStr( const std::string& aStr )
{
	eLookFilterStyle result = eLookFilterStyle::UNDEFINED;

	if ( aStr == "BOHEMIAN" )
	{
		result = eLookFilterStyle::BOHEMIAN;
	}
	else if ( aStr == "CASUAL" )
	{
		result = eLookFilterStyle::CASUAL;
	}
	else if ( aStr == "CHIC" )
	{
		result = eLookFilterStyle::CHIC;
	}
	else if ( aStr == "CLASSIC" )
	{
		result = eLookFilterStyle::CLASSIC;
	}
	else if ( aStr == "COMMON" )
	{
		result = eLookFilterStyle::COMMON;
	}
	else if ( aStr == "GLAM" )
	{
		result = eLookFilterStyle::GLAM;
	}
	else if ( aStr == "ROCKER" )
	{
		result = eLookFilterStyle::ROCKER;
	}
	else if ( aStr == "ROMANTIC" )
	{
		result = eLookFilterStyle::ROMANTIC;
	}
	else if ( aStr == "VINTAGE" )
	{
		result = eLookFilterStyle::VINTAGE;
	}
	else if ( aStr == "SPORTY" )
	{
		result = eLookFilterStyle::SPORTY;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookFilterStyle( eLookFilterStyle aLookFilterPattern )
{
	std::string result;

	if ( aLookFilterPattern == eLookFilterStyle::BOHEMIAN )
	{
		result = "BOHEMIAN";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::CASUAL )
	{
		result = "CASUAL";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::CHIC )
	{
		result = "CHIC";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::CLASSIC )
	{
		result = "CLASSIC";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::COMMON )
	{
		result = "COMMON";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::GLAM )
	{
		result = "GLAM";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::ROCKER )
	{
		result = "ROCKER";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::ROMANTIC )
	{
		result = "ROMANTIC";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::SPORTY )
	{
		result = "SPORTY";
	}
	else if ( aLookFilterPattern == eLookFilterStyle::VINTAGE )
	{
		result = "VINTAGE";
	}
	else
	{
		result = "UNDEFINED";
	}

	return result;
}

eLookFilterQuest DataTypesHelper::getLookFilterQuestFromStr(const std::string& aStr)
{
    eLookFilterQuest result = eLookFilterQuest::UNDEFINED;

    if (aStr == "WITHOUT_COTTON")
    {
        result = eLookFilterQuest::WITHOUT_COTTON;
    }
    else if (aStr == "WITHOUT_LEATHER")
    {
        result = eLookFilterQuest::WITHOUT_LEATHER;
    }
    else if (aStr == "WITHOUT_BLACK")
    {
        result = eLookFilterQuest::WITHOUT_BLACK;
    }
    else if (aStr == "WITHOUT_WHITE")
    {
        result = eLookFilterQuest::WITHOUT_WHITE;
    }
    else if (aStr == "WITHOUT_GRAY")
    {
        result = eLookFilterQuest::WITHOUT_GRAY;
    }
    else if (aStr == "WITH_DENIM")
    {
        result = eLookFilterQuest::WITH_DENIM;
    }
    else if (aStr == "WITH_LEAHTER")
    {
        result = eLookFilterQuest::WITH_LEAHTER;
    }
    else if (aStr == "WITH_TREND")
    {
        result = eLookFilterQuest::WITH_TREND;
    }
    else if (aStr == "WITH_NEW")
    {
        result = eLookFilterQuest::WITH_NEW;
    }
    else if (aStr == "END")
    {
        result = eLookFilterQuest::FILTER_END;
    }

    return result;
}

std::string DataTypesHelper::getStrFromLookFilterQuest(eLookFilterQuest aLookFilterPattern)
{
    std::string result;

    switch (aLookFilterPattern)
    {
    case eLookFilterQuest::WITHOUT_COTTON:
        result = "WITHOUT_COTTON";
        break;
    case eLookFilterQuest::WITHOUT_LEATHER:
        result = "WITHOUT_LEATHER";
        break;
    case eLookFilterQuest::WITHOUT_BLACK:
        result = "WITHOUT_BLACK";
        break;
    case eLookFilterQuest::WITHOUT_WHITE:
        result = "WITHOUT_WHITE";
        break;
    case eLookFilterQuest::WITHOUT_GRAY:
        result = "WITHOUT_GRAY";
        break;
    case eLookFilterQuest::WITH_DENIM:
        result = "WITH_DENIM";
        break;
    case eLookFilterQuest::WITH_LEAHTER:
        result = "WITH_LEAHTER";
        break;
    case eLookFilterQuest::WITH_TREND:
        result = "WITH_TREND";
        break;
    case eLookFilterQuest::WITH_NEW:
        result = "WITH_NEW";
        break;
    default:
        result = "UNDEFINED";
        break;
    };

    return result;
}

eLookFilterCollection DataTypesHelper::getLookFilterCollectionFromStr(const std::string& aStr)
{
    eLookFilterCollection result = eLookFilterCollection::UNDEFINED;

    if (aStr == "NEW")
    {
        result = eLookFilterCollection::NEW;
    }
    else if (aStr == "LOOK_OF_THE_DAY")
    {
        result = eLookFilterCollection::LOOK_OF_THE_DAY;
    }
	else if (aStr == GET_STRING("TT_FILTERS_STYLE_BTN_USER_CREATED"))
	{
		result = eLookFilterCollection::USER_CREATED;
	}
    else if (aStr == "END")
    {
        result = eLookFilterCollection::FILTER_END;
    }

    return result;
}

std::string DataTypesHelper::getStrFromLookFilterCollection(eLookFilterCollection lookFilterPattern)
{
    std::string result;

    switch (lookFilterPattern)
    {
    case eLookFilterCollection::NEW:
        result = "NEW";
        break;
    case eLookFilterCollection::LOOK_OF_THE_DAY:
        result = "LOOK_OF_THE_DAY";
        break;
    default:
        result = "UNDEFINED";
        break;
    };

    return result;
}

eLookFilterPattern DataTypesHelper::getLookFilterPatternFromStr(const std::string& aStr)
{
	eLookFilterPattern result = eLookFilterPattern::UNDEFINED;

	if ( aStr == "POLKA_DOTS" )
	{
		result = eLookFilterPattern::POLKA_DOTS;
	}
	else if ( aStr == "TIGER" )
	{
		result = eLookFilterPattern::TIGER;
	}
	else if ( aStr == "FLOWER" )
	{
		result = eLookFilterPattern::FLOWER;
	}
	else if ( aStr == "ABSTRACT" )
	{
		result = eLookFilterPattern::ABSTRACT;
	}
	else if ( aStr == "SOLYD" )
	{
		result = eLookFilterPattern::SOLYD;
	}
	else if ( aStr == "STRIPES" )
	{
		result = eLookFilterPattern::STRIPES;
	}
	else if ( aStr == "PLAID" )
	{
		result = eLookFilterPattern::PLAID;
	}
	else if ( aStr == "END" )
	{
		result = eLookFilterPattern::FILTER_END;
	}

	return result;
}

std::string DataTypesHelper::getStrFromLookFilterPattern(eLookFilterPattern aLookFilterPattern)
{
	std::string result;

	switch ( aLookFilterPattern )
	{
		case eLookFilterPattern::POLKA_DOTS:
			result = "POLKA_DOTS";
			break;
		case eLookFilterPattern::TIGER:
			result = "TIGER";
			break;
		case eLookFilterPattern::FLOWER:
			result = "FLOWER";
			break;
		case eLookFilterPattern::ABSTRACT:
			result = "ABSTRACT";
			break;
		case eLookFilterPattern::SOLYD:
			result = "SOLYD";
			break;
		case eLookFilterPattern::STRIPES:
			result = "STRIPES";
			break;
		case eLookFilterPattern::PLAID:
			result = "PLAID";
			break;
		default:
			result = "UNDEFINED";
			break;
	};

	return result;
}

eEffectType DataTypesHelper::getEffectTypeFromStr(const std::string& aStr)
{
	eEffectType result = eEffectType::UNDEFINED;

	if (aStr == "NONE")
	{
		result = eEffectType::NONE;
	}
	else if (aStr == "EXTRA_CASH" )
	{
		result = eEffectType::EXTRA_CASH;
	}
	else if (aStr == "EXTRA_RATING" )
	{
		result = eEffectType::EXTRA_RATING;
	}
	else if (aStr == "BONUS_STARS")
	{
		result = eEffectType::BONUS_STARS;
	}

	return result;
}
std::string DataTypesHelper::getStrFromEffectType(eEffectType aCurrencyType)
{
	std::string result;

	switch (aCurrencyType) {
	case eEffectType::UNDEFINED:
		result = "UNDEFINED";
		break;
	case eEffectType::NONE:
		result = "NONE";
		break;
	case eEffectType::EXTRA_CASH:
		result = "EXTRA_CASH";
		break;
	case eEffectType::EXTRA_RATING:
		result = "EXTRA_RATING";
		break;
	case eEffectType::BONUS_STARS:
		result = "BONUS_STARS";
		break;
	default:
		result = "UNDEFINED";
		break;
	}

	return result;
}


eCurrencyType DataTypesHelper::getCurrencyTypeFromStr(const std::string& aStr)
{
	eCurrencyType result = eCurrencyType::UNDEFINED;

	if ( aStr == "NONE" )
	{
		result = eCurrencyType::NONE;
	}
	else if ( aStr == "cash" || aStr == "CASH" )
	{
		result = eCurrencyType::CASH;
	}
	else if ( aStr == "crystals" || aStr == "CRYSTALS" )
	{
		result = eCurrencyType::CRYSTALS;
	}
	else if ( aStr == "TICKET" )
	{
		result = eCurrencyType::TICKET;
	}

	return result;
}
std::string DataTypesHelper::getStrFromCurrencyType(eCurrencyType aCurrencyType)
{
	std::string result;

	switch ( aCurrencyType ) {
		case eCurrencyType::UNDEFINED:
			result = "UNDEFINED";
			break;
		case eCurrencyType::NONE:
			result = "NONE";
			break;
		case eCurrencyType::CASH:
			result = "cash";
			break;
		case eCurrencyType::CRYSTALS:
			result = "crystals";
			break;
		case eCurrencyType::TICKET:
			result = "TICKET";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}
eCurrencyType DataTypesHelper::getCurrencyTypeFromRewardType(eRewardType aRewardType)
{
	eCurrencyType result = eCurrencyType::UNDEFINED;

	switch ( aRewardType )
	{
		case eRewardType::UNDEFINED:
			result = eCurrencyType::UNDEFINED;
			break;
		case eRewardType::CASH:
			result = eCurrencyType::CASH;
			break;
		case eRewardType::CRYSTALS:
			result = eCurrencyType::CRYSTALS;
			break;
		case eRewardType::TICKET:
			result = eCurrencyType::TICKET;
			break;
		default:
			result = eCurrencyType::UNDEFINED;
			break;
	}

	return result;
}
eCharFacePart DataTypesHelper::getCharFacePartFromStr(const std::string& aStr)
{
	eCharFacePart result = eCharFacePart::UNDEFINED;

	if ( aStr == "EYES" )
	{
		result = eCharFacePart::EYES;
	}
	else if ( aStr == "BROWS" )
	{
		result = eCharFacePart::BROWS;
	}
	else if ( aStr == "NOSE" )
	{
		result = eCharFacePart::NOSE;
	}
	else if ( aStr == "LIPS" )
	{
		result = eCharFacePart::LIPS;
	}
	else if ( aStr == "JAW" )
	{
		result = eCharFacePart::JAW;
	}
	else if ( aStr == "MAKEUP_EYES" )
	{
		result = eCharFacePart::MAKEUP_EYES;
	}
	else if ( aStr == "MAKEUP_LIPS" )
	{
		result = eCharFacePart::MAKEUP_LIPS;
	}
	else if ( aStr == "PIERCING" )
	{
		result = eCharFacePart::PIERCING;
	}
	else if ( aStr == "HEAD" )
	{
		result = eCharFacePart::HEAD;
	}

	return result;
}
std::string DataTypesHelper::getStrFromCharFacePart(eCharFacePart aFacePart)
{
	std::string result;

	switch ( aFacePart ) {
		case eCharFacePart::EYES:
			result = "EYES";
			break;
		case eCharFacePart::BROWS:
			result = "BROWS";
			break;
		case eCharFacePart::NOSE:
			result = "NOSE";
			break;
		case eCharFacePart::LIPS:
			result = "LIPS";
			break;
		case eCharFacePart::JAW:
			result = "JAW";
			break;
		case eCharFacePart::MAKEUP_EYES:
			result = "MAKEUP_EYES";
			break;
		case eCharFacePart::MAKEUP_LIPS:
			result = "MAKEUP_LIPS";
			break;
		case eCharFacePart::PIERCING:
			result = "PIERCING";
			break;
		case eCharFacePart::HEAD:
			result = "HEAD";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

eBrandIconColorizedPart DataTypesHelper::getIconColorizedPartFromStr(const std::string& aStr)
{
    eBrandIconColorizedPart result = eBrandIconColorizedPart::ICON_BADGE;

    if (aStr == "UNDEFINED")
    {
        result = eBrandIconColorizedPart::UNDEFINED;
    }
    else if (aStr == "ICON_BADGE")
    {
        result = eBrandIconColorizedPart::ICON_BADGE;
    }
    else if (aStr == "ICON_BACK")
    {
        result = eBrandIconColorizedPart::ICON_BACK;
    }

    return result;
}

eCharColorizedPart DataTypesHelper::getCharColorizedPartFromStr(const std::string& aStr)
{
	eCharColorizedPart result = eCharColorizedPart::EYES;

	if ( aStr == "UNDEFINED" )
	{
		result = eCharColorizedPart::UNDEFINED;
	}
	else if ( aStr == "EYES" )
	{
		result = eCharColorizedPart::EYES;
	}
	else if ( aStr == "BROWS" )
	{
		result = eCharColorizedPart::BROWS;
	}
	else if ( aStr == "HAIR_ROOTS" )
	{
		result = eCharColorizedPart::HAIR_ROOTS;
	}
	else if ( aStr == "HAIR_HIGHTLIGHTS" )
	{
		result = eCharColorizedPart::HAIR_HIGHTLIGHTS;
	}

	return result;
}
std::string DataTypesHelper::getStrFromCharColorizedPart(eCharColorizedPart aColorPart)
{
	std::string result;

	switch ( aColorPart ) {
		case eCharColorizedPart::UNDEFINED:
			result = "UNDEFINED";
			break;
		case eCharColorizedPart::EYES:
			result = "EYES";
			break;
		case eCharColorizedPart::BROWS:
			result = "BROWS";
			break;
		case eCharColorizedPart::HAIR_ROOTS:
			result = "HAIR_ROOTS";
			break;
		case eCharColorizedPart::HAIR_HIGHTLIGHTS:
			result = "HAIR_HIGHTLIGHTS";
			break;
		default:
			break;
	}

	return result;
}
/* eLookCustomFilterDress */
eLookCustomFilterDress DataTypesHelper::getLookCustomFilterDressFromStr(const std::string& aStr)
{
	eLookCustomFilterDress result = eLookCustomFilterDress::UNDEFINED;

	if ( aStr == "MINI_DRESS" )
	{
		result = eLookCustomFilterDress::MINI_DRESS;
	}
	else if ( aStr == "JUMPSUIT" )
	{
		result = eLookCustomFilterDress::JUMPSUIT;
	}
	else if ( aStr == "MIDI_DRESS" )
	{
		result = eLookCustomFilterDress::MIDI_DRESS;
	}
	else if ( aStr == "MAXI_DRESS" )
	{
		result = eLookCustomFilterDress::MAXI_DRESS;
	}

	else if ( aStr == "END" )
	{
		result = eLookCustomFilterDress::FILTER_END;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilterDress(eLookCustomFilterDress aCustomFilter)
{
	std::string result;

	switch ( aCustomFilter ) {
		case eLookCustomFilterDress::MINI_DRESS:
			result = "MINI_DRESS";
			break;
		case eLookCustomFilterDress::JUMPSUIT:
			result = "JUMPSUIT";
			break;
		case eLookCustomFilterDress::MIDI_DRESS:
			result = "MIDI_DRESS";
			break;
		case eLookCustomFilterDress::MAXI_DRESS:
			result = "MAXI_DRESS";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

/* eLookCustomFilterBottom */
eLookCustomFilterBottom DataTypesHelper::getLookCustomFilterBottomFromStr(const std::string& aStr)
{
	eLookCustomFilterBottom result = eLookCustomFilterBottom::UNDEFINED;

	if ( aStr == "TROUSERS" )
	{
		result = eLookCustomFilterBottom::TROUSERS;
	}
	else if ( aStr == "SHORTS" )
	{
		result = eLookCustomFilterBottom::SHORTS;
	}
	else if ( aStr == "SKIRT" )
	{
		result = eLookCustomFilterBottom::SKIRT;
	}
	else if ( aStr == "END" )
	{
		result = eLookCustomFilterBottom::FILTER_END;
	}
    else if (aStr == "LEGGINGS")
    {
        result = eLookCustomFilterBottom::LEGGINGS;
    }
	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilterBottom(eLookCustomFilterBottom aCustomFilter)
{
	std::string result;

	switch ( aCustomFilter ) {
		case eLookCustomFilterBottom::TROUSERS:
			result = "TROUSERS";
			break;
		case eLookCustomFilterBottom::SHORTS:
			result = "SHORTS";
			break;
		case eLookCustomFilterBottom::SKIRT:
			result = "SKIRT";
			break;
        case eLookCustomFilterBottom::LEGGINGS:
            result = "LEGGINGS";
            break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

/* eLookCustomFilterShoes */
eLookCustomFilterShoes DataTypesHelper::getLookCustomFilterShoesFromStr(const std::string& aStr)
{
	eLookCustomFilterShoes result = eLookCustomFilterShoes::UNDEFINED;

	if ( aStr == "HEELS" )
	{
		result = eLookCustomFilterShoes::HEELS;
	}
	else if ( aStr == "FLATS" )
	{
		result = eLookCustomFilterShoes::FLATS;
	}
	else if ( aStr == "BOOTS" )
	{
		result = eLookCustomFilterShoes::BOOTS;
	}
	else if ( aStr == "SNEAKERS" )
	{
		result = eLookCustomFilterShoes::SNEAKERS;
	}

	else if ( aStr == "END" )
	{
		result = eLookCustomFilterShoes::FILTER_END;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilterShoes(eLookCustomFilterShoes aCustomFilter)
{
	std::string result;

	switch ( aCustomFilter ) {
		case eLookCustomFilterShoes::HEELS:
			result = "HEELS";
			break;
		case eLookCustomFilterShoes::FLATS:
			result = "FLATS";
			break;
		case eLookCustomFilterShoes::BOOTS:
			result = "BOOTS";
			break;
		case eLookCustomFilterShoes::SNEAKERS:
			result = "SNEAKERS";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

/* eLookCustomFilterAccessories */
eLookCustomFilterAccessories DataTypesHelper::getLookCustomFilterAccessoriesFromStr(const std::string& aStr)
{
	eLookCustomFilterAccessories result = eLookCustomFilterAccessories::UNDEFINED;

	if ( aStr == "JEWELRY" )
	{
		result = eLookCustomFilterAccessories::JEWELRY;
	}
	else if ( aStr == "BAG" )
	{
		result = eLookCustomFilterAccessories::BAG;
	}
	else if ( aStr == "GLASSES" )
	{
		result = eLookCustomFilterAccessories::GLASSES;
	}
	else if ( aStr == "BROOCH" )
	{
		result = eLookCustomFilterAccessories::BROOCH;
	}
	else if ( aStr == "SCARF" )
	{
		result = eLookCustomFilterAccessories::SCARF;
	}
	else if ( aStr == "HAT" )
	{
		result = eLookCustomFilterAccessories::HAT;
	}
	else if ( aStr == "BELT" )
	{
		result = eLookCustomFilterAccessories::BELT;
	}
	else if ( aStr == "GLOVES" )
	{
		result = eLookCustomFilterAccessories::GLOVES;
	}
	else if ( aStr == "STOCKINGS" )
	{
		result = eLookCustomFilterAccessories::STOCKINGS;
	}

	else if ( aStr == "END" )
	{
		result = eLookCustomFilterAccessories::FILTER_END;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilterAccessories(eLookCustomFilterAccessories aCustomFilter)
{
	std::string result;

	switch ( aCustomFilter ) {
		case eLookCustomFilterAccessories::JEWELRY:
			result = "JEWELRY";
			break;
		case eLookCustomFilterAccessories::BAG:
			result = "BAG";
			break;
		case eLookCustomFilterAccessories::GLASSES:
			result = "GLASSES";
			break;
		case eLookCustomFilterAccessories::BROOCH:
			result = "BROOCH";
			break;
		case eLookCustomFilterAccessories::SCARF:
			result = "SCARF";
			break;
		case eLookCustomFilterAccessories::HAT:
			result = "HAT";
			break;
		case eLookCustomFilterAccessories::BELT:
			result = "BELT";
			break;
		case eLookCustomFilterAccessories::GLOVES:
			result = "GLOVES";
			break;
		case eLookCustomFilterAccessories::STOCKINGS:
			result = "STOCKINGS";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

/* eLookCustomFilterTopA */
eLookCustomFilterTopA DataTypesHelper::getLookCustomFilterTopAFromStr(const std::string& aStr)
{
	eLookCustomFilterTopA result = eLookCustomFilterTopA::UNDEFINED;

	if ( aStr == "SHIRT" )
	{
		result = eLookCustomFilterTopA::SHIRT;
	}
	else if ( aStr == "SWEATER" )
	{
		result = eLookCustomFilterTopA::SWEATER;
	}
	else if ( aStr == "BLOUSE" )
	{
		result = eLookCustomFilterTopA::BLOUSE;
	}
	else if ( aStr == "END" )
	{
		result = eLookCustomFilterTopA::FILTER_END;
	}
	else if ( aStr == "CROP_TOP" )
	{
		result = eLookCustomFilterTopA::CROP_TOP;
	}
	else if ( aStr == "SLEEVELESS_SHIRT" )
	{
		result = eLookCustomFilterTopA::SLEEVELESS_SHIRT;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilterTopA(eLookCustomFilterTopA aCustomFilter)
{
	std::string result;

	switch ( aCustomFilter ) {
		case eLookCustomFilterTopA::SHIRT:
			result = "SHIRT";
			break;
		case eLookCustomFilterTopA::SWEATER:
			result = "SWEATER";
			break;
		case eLookCustomFilterTopA::BLOUSE:
			result = "BLOUSE";
			break;
		case eLookCustomFilterTopA::CROP_TOP:
			result = "CROP_TOP";
			break;
		case eLookCustomFilterTopA::SLEEVELESS_SHIRT:
			result = "SLEEVELESS_SHIRT";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

/* eLookCustomFilterTopB */
eLookCustomFilterTopB DataTypesHelper::getLookCustomFilterTopBFromStr(const std::string& aStr)
{
	eLookCustomFilterTopB result = eLookCustomFilterTopB::UNDEFINED;

	if ( aStr == "JACKET" )
	{
		result = eLookCustomFilterTopB::JACKET;
	}
	else if ( aStr == "COAT" )
	{
		result = eLookCustomFilterTopB::COAT;
	}
	else if ( aStr == "VEST" )
	{
		result = eLookCustomFilterTopB::VEST;
	}
	else if ( aStr == "PONCHO" )
	{
		result = eLookCustomFilterTopB::PONCHO;
	}

	else if ( aStr == "END" )
	{
		result = eLookCustomFilterTopB::FILTER_END;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilterTopB(eLookCustomFilterTopB aCustomFilter)
{
	std::string result;

	switch ( aCustomFilter ) {
		case eLookCustomFilterTopB::JACKET:
			result = "JACKET";
			break;
		case eLookCustomFilterTopB::COAT:
			result = "COAT";
			break;
		case eLookCustomFilterTopB::VEST:
			result = "VEST";
			break;
		case eLookCustomFilterTopB::PONCHO:
			result = "PONCHO";
			break;
		default:
			result = "UNDEFINED";
			break;
	}

	return result;
}

eEventDifficulty DataTypesHelper::getEventDifficultyFromStr(const std::string& aStr)
{
	eEventDifficulty result = eEventDifficulty::UNDEFINED;

	if ( aStr == "FREE" )
	{
		result = eEventDifficulty::FREE;
	}
	else if ( aStr == "EASY_1" )
	{
		result = eEventDifficulty::EASY_1;
	}
	else if ( aStr == "EASY_2" )
	{
		result = eEventDifficulty::EASY_2;
	}
	else if ( aStr == "EASY_3" )
	{
		result = eEventDifficulty::EASY_3;
	}
	else if ( aStr == "EASY_4" )
	{
		result = eEventDifficulty::EASY_4;
	}
	else if ( aStr == "MEDIUM_1" )
	{
		result = eEventDifficulty::MEDIUM_1;
	}
	else if ( aStr == "MEDIUM_2" )
	{
		result = eEventDifficulty::MEDIUM_2;
	}
	else if ( aStr == "MEDIUM_3" )
	{
		result = eEventDifficulty::MEDIUM_3;
	}
	else if ( aStr == "MEDIUM_4" )
	{
		result = eEventDifficulty::MEDIUM_4;
	}
	else if ( aStr == "MEDIUM_5" )
	{
		result = eEventDifficulty::MEDIUM_5;
	}
	else if ( aStr == "MEDIUM_6" )
	{
		result = eEventDifficulty::MEDIUM_6;
	}
	else if ( aStr == "MEDIUM_7" )
	{
		result = eEventDifficulty::MEDIUM_7;
	}
	else if ( aStr == "HARD_1" )
	{
		result = eEventDifficulty::HARD_1;
	}
	else if ( aStr == "HARD_2" )
	{
		result = eEventDifficulty::HARD_2;
	}
	else if ( aStr == "HARD_3" )
	{
		result = eEventDifficulty::HARD_3;
	}
	else if ( aStr == "HARD_4" )
	{
		result = eEventDifficulty::HARD_4;
	}

	return result;
}

std::string DataTypesHelper::getStringFromEventDifficulty(eEventDifficulty aEventDifficulty)
{
	std::string result;

	switch ( aEventDifficulty ) {
		case eEventDifficulty::FREE:
			result = "FREE";
			break;
		case eEventDifficulty::EASY_1:
			result = "EASY_1";
			break;
		case eEventDifficulty::EASY_2:
			result = "EASY_2";
			break;
		case eEventDifficulty::EASY_3:
			result = "EASY_3";
			break;
		case eEventDifficulty::EASY_4:
			result = "EASY_4";
			break;
		case eEventDifficulty::MEDIUM_1:
			result = "MEDIUM_1";
			break;
		case eEventDifficulty::MEDIUM_2:
			result = "MEDIUM_2";
			break;
		case eEventDifficulty::MEDIUM_3:
			result = "MEDIUM_3";
			break;
		case eEventDifficulty::MEDIUM_4:
			result = "MEDIUM_4";
			break;
		case eEventDifficulty::MEDIUM_5:
			result = "MEDIUM_5";
			break;
		case eEventDifficulty::MEDIUM_6:
			result = "MEDIUM_6";
			break;
		case eEventDifficulty::MEDIUM_7:
			result = "MEDIUM_7";
			break;
		case eEventDifficulty::HARD_1:
			result = "HARD_1";
			break;
		case eEventDifficulty::HARD_2:
			result = "HARD_2";
			break;
		case eEventDifficulty::HARD_3:
			result = "HARD_3";
			break;
		case eEventDifficulty::HARD_4:
			result = "HARD_4";
			break;
		default:
			break;
	}

	return result;
}

eRewardType DataTypesHelper::getEventRewardTypeFromString(const std::string& aStr)
{
	eRewardType result = eRewardType::UNDEFINED;

	if ( aStr == "CASH" || aStr == "cash" )
	{
		result = eRewardType::CASH;
	}
	else if (aStr == "CONS_PERFUME_CRYSTALS" || aStr == "cons_perfume_crystals")
	{
		result = eRewardType::CONS_PERFUME_CRYSTALS;
	}
	else if (aStr == "CONS_GLITTER_CRYSTALS" || aStr == "cons_glitter_crystals")
	{
		result = eRewardType::CONS_GLITTER_CRYSTALS;
	}
	else if (aStr == "CONS_PERFUME_CASH" || aStr == "cons_perfume_cash")
	{
		result = eRewardType::CONS_PERFUME_CASH;
	}
	else if (aStr == "CONS_GLITTER_CASH" || aStr == "cons_glitter_cash")
	{
		result = eRewardType::CONS_GLITTER_CASH;
	}
	else if ( aStr == "CRYSTALS" || aStr == "crystals")
	{
		result = eRewardType::CRYSTALS;
	}
	else if ( aStr == "EXP" || aStr == "exp")
	{
		result = eRewardType::EXP;
	}
	else if ( aStr == "ITEM" || aStr == "item" || aStr == "cons_item")
	{
		result = eRewardType::ITEM;
	}
	else if ( aStr == "TICKET" || aStr == "ticket")
	{
		result = eRewardType::TICKET;
	}
	else if ( aStr == "INFL_SCORE" || aStr == "infl_score")
	{
		result = eRewardType::INFL_SCORE;
	}
	else if (aStr == "SPECIAL_EVENT_STARS" || aStr == "special_event_stars")
	{
		result = eRewardType::SPECIAL_EVENT_STARS;
	}
	else if (aStr == "LIMITED_ITEM" || aStr == "limited_item")
	{
		result = eRewardType::LIMITED_ITEM;
	}
	else if (aStr == "RUNWAY_DUEL_SCORE" || aStr == "runway_duel_score")
	{
		result = eRewardType::RUNWAY_DUEL_SCORE;
	}
	else if (aStr == "RUNWAY_DUEL_WIN_DUEL" || aStr == "runway_duel_win_duel")
	{
		result = eRewardType::RUNWAY_DUEL_WIN_DUEL;
	}
	else if (aStr == "TOTAL_PARTICIPATED_SEASONS" || aStr == "total_participated_seasons")
	{
		result = eRewardType::TOTAL_PARTICIPATED_SEASONS;
	}
	else if ( aStr == "double" || aStr == "DOUBLE" )
	{
		result = eRewardType::DOUBLE;
	}
	else if (aStr == "MARATHON_TOKEN" || aStr == "marathon_token")
	{
		result = eRewardType::MARATHON_TOKENS;
	}
    else if (aStr ==  "HOLIDAY_TOKEN" || aStr == "holiday_token")
    {
        result = eRewardType::MARATHON_HOLIDAY;
    }
	else if (aStr == "TIME" || aStr == "time")
	{
		result = eRewardType::TIME;
	}
	else if (aStr == "DESIGNER_EXP" || aStr == "designer_exp")
	{
		result = eRewardType::DESIGNER_EXP;
	}

	return result;
}

std::string DataTypesHelper::getStringFromEvetRewardType(eRewardType aRewardType)
{
	std::string result;

	switch ( aRewardType ) {
		case eRewardType::EXP:
			result = "EXP";
			break;
		case eRewardType::CASH:
			result = "CASH";
			break;
		case eRewardType::CRYSTALS:
			result = "CRYSTALS";
			break;
		case eRewardType::ITEM:
			result = "ITEM";
			break;
		case eRewardType::TICKET:
			result = "TICKET";
			break;
		case eRewardType::INFL_SCORE:
			result = "INFL_SCORE";
			break;
		case eRewardType::RUNWAY_DUEL_SCORE:
			result = "RUNWAY_DUEL_SCORE";
			break;
		case eRewardType::DOUBLE:
			result = "double";
			break;
		default:
			break;
	}

	return result;
}

eRewardType DataTypesHelper::getRewardTypeFromCurrencyType(eCurrencyType currencyType)
{
	eRewardType result = eRewardType::UNDEFINED;

	switch ( currencyType )
	{
		case eCurrencyType::NONE:
			result = eRewardType::UNDEFINED;
			break;
		case eCurrencyType::CASH:
			result = eRewardType::CASH;
			break;
		case eCurrencyType::CRYSTALS:
			result = eRewardType::CRYSTALS;
			break;
		case eCurrencyType::TICKET:
			result = eRewardType::TICKET;
			break;
		default:
			result = eRewardType::UNDEFINED;
			break;
	}

	return result;
}

void DataTypesHelper::getStringFromDailyRewardsPoolType(eDailyRewardsPoolType aType, std::string & aResult)
{
	switch (aType)
	{
	case eDailyRewardsPoolType::BASIC:
	{
		aResult = "BASIC";
		break;
	}
	case eDailyRewardsPoolType::SIMPLE:
	{
		aResult = "SIMPLE";
		break;
	}
	case eDailyRewardsPoolType::MEDIUM:
	{
		aResult = "MEDIUM";
		break;
	}
	case eDailyRewardsPoolType::TOP:
	{
		aResult = "TOP";
		break;
	}
	default:
	{
		aResult = "UNDEFINED";
		break;
	}
	}
}

eDailyRewardsPoolType DataTypesHelper::getDailyRewardPoolTypeFromString(const std::string & aType)
{
	eDailyRewardsPoolType type = eDailyRewardsPoolType::UNDEFINED;

	if (aType == "BASIC")
	{
		type = eDailyRewardsPoolType::BASIC;
	}
	else if (aType == "SIMPLE")
	{
		type = eDailyRewardsPoolType::SIMPLE;
	}
	else if (aType == "MEDIUM")
	{
		type = eDailyRewardsPoolType::MEDIUM;
	}
	else if (aType == "TOP")
	{
		type = eDailyRewardsPoolType::TOP;
	}

	return type;
}

eEventType DataTypesHelper::getEventTypeFromStr(const std::string& aStr)
{
	eEventType result = eEventType::UNDEFINED;

	if ( aStr == "DAILY" )
	{
		result = eEventType::DAILY;
	}
	else if ( aStr == "REGULAR" )
	{
		result = eEventType::REGULAR;
	}
	else if ( aStr == "CUSTOM" )
	{
		result = eEventType::CUSTOM;
	}
	else if ( aStr == "SPECIAL" )
	{
		result = eEventType::SPECIAL;
	}
	return result;
}

std::string DataTypesHelper::getStrFromEventType(eEventType aEventType)
{
	std::string result;

	switch ( aEventType ) {
		case eEventType::DAILY:
			result = "DAILY";
			break;
		case eEventType::CUSTOM:
			result = "CUSTOM";
			break;
		case eEventType::REGULAR:
			result = "REGULAR";
			break;
		case eEventType::SPECIAL:
			result = "SPECIAL";
			break;
		default:
			break;
	}

	return result;
}

eEventVisibility DataTypesHelper::getEventVisibilityFromStr(const std::string& aStr)
{
	eEventVisibility result = eEventVisibility::UNDEFINED;

	if ( aStr == "REGULAR" )
	{
		result = eEventVisibility::REGULAR;
	}
	else if ( aStr == "SHARED" )
	{
		result = eEventVisibility::SHARED;
	}
	else if ( aStr == "NEWCOMER" )
	{
		result = eEventVisibility::NEWCOMER;
	}
	else if ( aStr == "NEWCOMER_SHORT" )
	{
		result = eEventVisibility::NEWCOMER_SHORT;
	}

	return result;
}
std::string DataTypesHelper::getStrFromEventVisibility(eEventVisibility aEventVisibility)
{
	std::string result;

	switch ( aEventVisibility ) {
		case eEventVisibility::REGULAR:
			result = "REGULAR";
			break;
		case eEventVisibility::SHARED:
			result = "SHARED";
			break;
		case eEventVisibility::NEWCOMER:
			result = "NEWCOMER";
			break;
		default:
			break;
	}

	return result;
}

std::vector< int > DataTypesHelper::getLookCustomFilterValuesVec(eLookType aLookType)
{
	std::vector< int > result;

	switch ( aLookType ) {
		case eLookType::DRESS:
		{
			for ( eLookCustomFilterDress filter = eLookCustomFilterDress::UNDEFINED; filter != eLookCustomFilterDress::FILTER_END; )
			{
				if ( filter != eLookCustomFilterDress::UNDEFINED )
				{
					result.push_back(static_cast<int>( filter ));
				}
				//increment
				filter = static_cast<eLookCustomFilterDress>( (int)filter + 1 );
			}
		}
		break;
		case eLookType::BOTTOM:
		{
			for ( eLookCustomFilterBottom filter = eLookCustomFilterBottom::UNDEFINED; filter != eLookCustomFilterBottom::FILTER_END; )
			{
				if ( filter != eLookCustomFilterBottom::UNDEFINED )
				{
					result.push_back(static_cast<int>( filter ));
				}
				//increment
				filter = static_cast<eLookCustomFilterBottom>( (int)filter + 1 );
			}
		}
		break;
		case eLookType::TOP_A:
		{
			for ( eLookCustomFilterTopA filter = eLookCustomFilterTopA::UNDEFINED; filter != eLookCustomFilterTopA::FILTER_END; )
			{
				if ( filter != eLookCustomFilterTopA::UNDEFINED )
				{
					result.push_back(static_cast<int>( filter ));
				}
				//increment
				filter = static_cast<eLookCustomFilterTopA>( (int)filter + 1 );
			}
		}
		break;
		case eLookType::TOP_A_TUCKED:
		{
			for ( eLookCustomFilterTopA filter = eLookCustomFilterTopA::UNDEFINED; filter != eLookCustomFilterTopA::FILTER_END; )
			{
				if ( filter != eLookCustomFilterTopA::UNDEFINED )
				{
					result.push_back(static_cast<int>( filter ));
				}
				//increment
				filter = static_cast<eLookCustomFilterTopA>( (int)filter + 1 );
			}
		}
		break;
		case eLookType::TOP_B:
		{
			for ( eLookCustomFilterTopB filter = eLookCustomFilterTopB::UNDEFINED; filter != eLookCustomFilterTopB::FILTER_END; )
			{
				if ( filter != eLookCustomFilterTopB::UNDEFINED )
				{
					result.push_back(static_cast<int>( filter ));
				}
				//increment
				filter = static_cast<eLookCustomFilterTopB>( (int)filter + 1 );
			}
		}
		break;
		default:
		{
			if ( ISYSTEM->isLookTypeIsShoesType(aLookType) )
			{
				for ( eLookCustomFilterShoes filter = eLookCustomFilterShoes::UNDEFINED; filter != eLookCustomFilterShoes::FILTER_END;)
				{
					if ( filter != eLookCustomFilterShoes::UNDEFINED )
					{
						result.push_back(static_cast<int>( filter ));
					}
					//increment
					filter = static_cast<eLookCustomFilterShoes>( (int)filter + 1 );
				}
			}
			else if ( ISYSTEM->isLookTypeIsAccessoriesType(aLookType) )
			{
				for ( eLookCustomFilterAccessories filter = eLookCustomFilterAccessories::UNDEFINED; filter != eLookCustomFilterAccessories::FILTER_END; )
				{
					if ( filter != eLookCustomFilterAccessories::UNDEFINED )
					{
						result.push_back(static_cast<int>( filter ));
					}
					//increment
					filter = static_cast<eLookCustomFilterAccessories>( (int)filter + 1 );
				}
			}
		}
		break;
	}

	return result;
}
std::string DataTypesHelper::getStrFromLookCustomFilter(eLookType aLookType, int aCustomFilter)
{
	std::string result;

	switch ( aLookType ) {
		case eLookType::DRESS:
		{
			if ( aCustomFilter < static_cast<int>( eLookCustomFilterDress::FILTER_END ) )
			{
				result = getStrFromLookCustomFilterDress(static_cast<eLookCustomFilterDress>( aCustomFilter ));
			}
		}
		break;
		case eLookType::BOTTOM:
		{
			if ( aCustomFilter < static_cast<int>( eLookCustomFilterBottom::FILTER_END ) )
			{
				result = getStrFromLookCustomFilterBottom(static_cast<eLookCustomFilterBottom>( aCustomFilter ));
			}
		}
		break;
		case eLookType::TOP_A:
		{
			if ( aCustomFilter < static_cast<int>( eLookCustomFilterTopA::FILTER_END ) )
			{
				result = getStrFromLookCustomFilterTopA(static_cast<eLookCustomFilterTopA>( aCustomFilter ));
			}
		}
		case eLookType::TOP_A_TUCKED:
		{
			if ( aCustomFilter < static_cast<int>( eLookCustomFilterTopA::FILTER_END ) )
			{
				result = getStrFromLookCustomFilterTopA(static_cast<eLookCustomFilterTopA>( aCustomFilter ));
			}
		}
		break;
		case eLookType::TOP_B:
		{
			if ( aCustomFilter < static_cast<int>( eLookCustomFilterTopB::FILTER_END ) )
			{
				result = getStrFromLookCustomFilterTopB(static_cast<eLookCustomFilterTopB>( aCustomFilter ));
			}
		}
		break;
		default:
		{
			if ( ISYSTEM->isLookTypeIsShoesType(aLookType) )
			{
				if ( aCustomFilter < static_cast<int>( eLookCustomFilterShoes::FILTER_END ) )
				{
					result = getStrFromLookCustomFilterShoes(static_cast<eLookCustomFilterShoes>( aCustomFilter ));
				}
			}
			else if ( ISYSTEM->isLookTypeIsAccessoriesType(aLookType) )
			{
				if ( aCustomFilter < static_cast<int>( eLookCustomFilterAccessories::FILTER_END ) )
				{
					result = getStrFromLookCustomFilterAccessories(static_cast<eLookCustomFilterAccessories>( aCustomFilter ));
				}
			}
			break;
		}
		break;
	};

	return result;
}
int DataTypesHelper::getLookCustomFilterFromStr(eLookType aLookType, const std::string& aStr)
{
	int result = 0;

	switch ( aLookType ) {
		case eLookType::DRESS:
		{
			result = static_cast<int>( getLookCustomFilterDressFromStr(aStr) );
		}
		break;
		case eLookType::BOTTOM:
		{
			result = static_cast<int>( getLookCustomFilterBottomFromStr(aStr) );
		}
		break;
		case eLookType::TOP_A:
		{
			result = static_cast<int>( getLookCustomFilterTopAFromStr(aStr) );
		}
		break;
		case eLookType::TOP_A_TUCKED:
		{
			result = static_cast<int>( getLookCustomFilterTopAFromStr(aStr) );
		}
		break;
		case eLookType::TOP_B:
		{
			result = static_cast<int>( getLookCustomFilterTopBFromStr(aStr) );
		}
		break;
		default:
		{
			if ( ISYSTEM->isLookTypeIsShoesType(aLookType) )
			{
				result = static_cast<int>( getLookCustomFilterShoesFromStr(aStr) );
			}
			else if ( ISYSTEM->isLookTypeIsAccessoriesType(aLookType) )
			{
				result = static_cast<int>( getLookCustomFilterAccessoriesFromStr(aStr) );
			}
		}
		break;
	};

	return result;
}

eBonusType DataTypesHelper::getBonusTypeFromStr(const std::string& aStr)
{
	eBonusType result = eBonusType::UNDEFINED;

	if ( aStr == "NEW_ITEM_BONUS" )
	{
		result = eBonusType::NEW_ITEM_BONUS;
	}
	else if ( aStr == "BORROWED_ITEM_BONUS" )
	{
		result = eBonusType::BORROWED_ITEM_BONUS;
	}
	else if ( aStr == "TRENDING_ITEM_BONUS" )
	{
		result = eBonusType::TRENDING_ITEM_BONUS;
	}
	else if ( aStr == "SEASON_ITEM_BONUS" )
	{
		result = eBonusType::SEASON_ITEM_BONUS;
	}

	return result;
}

std::string DataTypesHelper::getStrFromBonusType(eBonusType aEventType)
{
	std::string result;

	switch ( aEventType ) {
		case eBonusType::TRENDING_ITEM_BONUS:
			result = "TRENDING_ITEM_BONUS";
			break;
		case eBonusType::NEW_ITEM_BONUS:
			result = "NEW_ITEM_BONUS";
			break;
		case eBonusType::BORROWED_ITEM_BONUS:
			result = "BORROWED_ITEM_BONUS";
			break;
		case eBonusType::SEASON_ITEM_BONUS:
			result = "SEASON_ITEM_BONUS";
			break;
		default:
			break;
	}

	return result;
}

std::string DataTypesHelper::getStrFromAspectRatioSkin(eGameAspectRatio aGameAspectRatio)
{
	std::string result = "DEFAULT";

	switch ( aGameAspectRatio )
	{
		case eGameAspectRatio::_16X9:
		{
			result = "SKIN_16_9";
			break;
		}
		case eGameAspectRatio::_4X3:
		{
			result = "SKIN_4_3";
			break;
		}
		case eGameAspectRatio::_19_5X9:
		{
			result = "DEFAULT";
			break;
		}
		case eGameAspectRatio::_14_4X9:
		{
			result = "SKIN_14_4_9";
			break;
		}
		case eGameAspectRatio::_18X9:
		{
			result = "SKIN_18_9";
			break;
		}
	}

	return result;
}

std::string DataTypesHelper::getStrFromTrackIndex(eTrackIndex aTrackIndex)
{
	std::string result;

	switch ( aTrackIndex ) {
		case eTrackIndex::TUCKED_BELT:
			result = "tucked_belt";
			break;
		case eTrackIndex::TOP_A_BELT:
			result = "top_a_belt";
			break;
		case eTrackIndex::BELT_SQUASH:
			result = "belt_squash";
			break;
		case eTrackIndex::BAG:
			result = "bag";
			break;
		case eTrackIndex::HAT_LOW:
			result = "hat_low";
			break;
		case eTrackIndex::HAT_HIGH:
			result = "hat_high";
			break;
		case eTrackIndex::BOOTS:
			result = "boots";
			break;
		case eTrackIndex::BA_UNDER_HIGH:
			result = "ba_under_high";
			break;
		case eTrackIndex::BA_UNDER_LOW:
			result = "ba_under_low";
			break;
		case eTrackIndex::BA_BELT:
			result = "ba_belt";
			break;
		case eTrackIndex::HIPS:
			result = "hips";
			break;
		case eTrackIndex::SHBAG:
			result = "shbag";
			break;
		case eTrackIndex::TOP_UNDER:
			result = "top_under";
			break;
		case eTrackIndex::UR_SQUASH:
			result = "ur_squash";
			break;
		case eTrackIndex::SCARF_A_SQUASH:
			result = "scarf_a_squash";
			break;
		case eTrackIndex::SCARF_A_UNDER:
			result = "scarf_a_under";
			break;
		case eTrackIndex::SCARF_AB_UNDER:
			result = "scarf_ab_under";
			break;
		case eTrackIndex::SCARF_OVER_A:
			result = "scarf_over_a";
			break;
		case eTrackIndex::SCARF_OVER_B:
			result = "scarf_over_b";
			break;
		case eTrackIndex::SCARF_OVER_C:
			result = "scarf_over_c";
			break;
		case eTrackIndex::SCARF_OVER_D:
			result = "scarf_over_d";
			break;
		case eTrackIndex::SCARF_OVER_E:
			result = "scarf_over_e";
			break;
		case eTrackIndex::SCARF_OVER_F:
			result = "scarf_over_f";
			break;
		case eTrackIndex::H_030_G:
			result = "h_030_g";
			break;
		case eTrackIndex::H_060_G:
			result = "h_060_g";
			break;
		case eTrackIndex::H_067_G:
			result = "h_067_g";
			break;
		case eTrackIndex::H_068_G:
			result = "h_068_g";
			break;
		case eTrackIndex::PANTS_ON:
			result = "pants_on";
			break;
		case eTrackIndex::BA_UNDER_MAX:
			result = "ba_under_max";
			break;
		case eTrackIndex::SLEEVE_SQUASH:
			result = "sleeve_squash";
			break;
		case eTrackIndex::BOOT_SQUASH:
			result = "boot_squash";
			break;
		case eTrackIndex::SOCKS_SQUASH:
			result = "socks_squash";
			break;
		case eTrackIndex::PANTS_SHORTER:
			result = "pants_shorter";
			break;
		case eTrackIndex::PANTS_WIDER:
			result = "pants_wider";
			break;
		case eTrackIndex::BELT_UNDER:
			result = "belt_under";
			break;
		case eTrackIndex::SOCKS_SQUASH_SMALL:
			result = "socks_squash_small";
			break;
		case eTrackIndex::FASHIONISTA_GLOVE:
			result = "fashionista_glove";
			break;
		case eTrackIndex::RINGER:
			result = "ringer";
			break;
		case eTrackIndex::NECKLACE_SQUASH:
			result = "necklace_squash";
			break;
		case eTrackIndex::GLOVE_SQUASH:
			result = "glove_squash";
			break;
        case eTrackIndex::REDUCE_NECKLACE:
            result = "reduce_necklace";
            break;
        case eTrackIndex::TOP_VEST:
            result = "top_vest";
            break;
		case eTrackIndex::TUCKED_SUSPENDER:
			result = "tucked_suspender";
			break;
		case eTrackIndex::MAKEUP_1:
			result = "makeup_1";
			break;
		case eTrackIndex::MAKEUP_2:
			result = "makeup_2";
			break;
		case eTrackIndex::MAKEUP_3:
			result = "makeup_3";
			break;
		case eTrackIndex::MAKEUP_4:
			result = "makeup_4";
			break;
		case eTrackIndex::MAKEUP_5:
			result = "makeup_5";
			break;
		case eTrackIndex::PREMIUM_1:
			result = "premium_1";
			break;
		case eTrackIndex::PREMIUM_2:
			result = "premium_2";
			break;
		case eTrackIndex::PREMIUM_3:
			result = "premium_3";
			break;
		case eTrackIndex::PREMIUM_4:
			result = "premium_4";
			break;
		case eTrackIndex::PREMIUM_5:
			result = "premium_5";
			break;
		case eTrackIndex::PREMIUM_6:
			result = "premium_6";
			break;
		case eTrackIndex::PREMIUM_7:
			result = "premium_7";
			break;
		case eTrackIndex::PREMIUM_8:
			result = "premium_8";
			break;
		case eTrackIndex::PREMIUM_9:
			result = "premium_9";
			break;
		case eTrackIndex::PREMIUM_10:
			result = "premium_10";
			break;
		case eTrackIndex::PREMIUM_11:
			result = "premium_11";
			break;
		default:
			result = "none";
			break;
	}

	return result;
}

std::string DataTypesHelper::getStrIDFromBanReasonType(eItemBanReasonType aReasonType)
{
    std::string result;

    switch (aReasonType) {
    case eItemBanReasonType::ABUSIVE_CONTENT:
        result = "TT_DESIGNER_ITEM_BAN_REASON_ABUSIVE_CONTENT";
        break;
    case eItemBanReasonType::COPYRIGHT_VIOLATION:
        result = "TT_DESIGNER_ITEM_BAN_REASON_COPYRIGHT_VIOLATION";
        break;
    case eItemBanReasonType::CRITICAL_DISPLAY_ARTIFACTS:
        result = "TT_DESIGNER_ITEM_BAN_REASON_CRITICAL_DISPLAY_ARTIFACTS";
        break;
    case eItemBanReasonType::INCORRECT_ATTRIBUTES:
        result = "TT_DESIGNER_ITEM_BAN_REASON_INCORRECT_ATTRIBUTES";
        break;
	case eItemBanReasonType::WRONG_SUBCATEGORY:
		result = "";
		break;
    default:
        result = "UNDEFINED";
        break;
    }

    return result;
}

std::string DataTypesHelper::getStrIDFromBanReasonHeaderType(eItemBanReasonType aReasonType)
{
	std::string result;

	switch (aReasonType) {
	case eItemBanReasonType::ABUSIVE_CONTENT:
		result = "TT_DESIGNER_ITEM_BAN_REASON_OFFENSIVE_CONTENT_HEADER";
		break;
	case eItemBanReasonType::COPYRIGHT_VIOLATION:
		result = "TT_DESIGNER_ITEM_BAN_REASON_COPYRIGHT_VIOLATION_HEADER";
		break;
	case eItemBanReasonType::CRITICAL_DISPLAY_ARTIFACTS:
		result = "TT_DESIGNER_ITEM_BAN_REASON_CRITICAL_DISPLAY_ARTIFACTS_HEADER";
		break;
	case eItemBanReasonType::INCORRECT_ATTRIBUTES:
		result = "TT_DESIGNER_ITEM_BAN_REASON_INCORRECT_ATTRIBUTES_HEADER";
		break;
	case eItemBanReasonType::WRONG_SUBCATEGORY:
		result = "TT_DESIGNER_ITEM_BAN_REASON_WRONG_SUBTYPE_HEADER";
		break;
	default:
		result = "UNDEFINED";
		break;
	}

	return result;
}

std::string DataTypesHelper::getStrIDFromBanReasonBodyType(eItemBanReasonType aReasonType)
{
	std::string result;

	switch (aReasonType) {
	case eItemBanReasonType::ABUSIVE_CONTENT:
		result = "TT_DESIGNER_ITEM_BAN_REASON_OFFENSIVE_CONTENT_BODY";
		break;
	case eItemBanReasonType::COPYRIGHT_VIOLATION:
		result = "TT_DESIGNER_ITEM_BAN_REASON_COPYRIGHT_VIOLATION_BODY";
		break;
	case eItemBanReasonType::CRITICAL_DISPLAY_ARTIFACTS:
		result = "TT_DESIGNER_ITEM_BAN_REASON_CRITICAL_DISPLAY_ARTIFACTS_BODY";
		break;
	case eItemBanReasonType::INCORRECT_ATTRIBUTES:
		result = "TT_DESIGNER_ITEM_BAN_REASON_INCORRECT_ATTRIBUTES_BODY";
		break;
	case eItemBanReasonType::WRONG_SUBCATEGORY:
		result = "TT_DESIGNER_ITEM_BAN_REASON_WRONG_SUBTYPE_BODY";
		break;
	default:
		result = "UNDEFINED";
		break;
	}

	return result;
}

eTrackIndex DataTypesHelper::getTrackIndexFromString(std::string aTrackName)
{
	eTrackIndex result = eTrackIndex::NONE;

	if (aTrackName == "tucked_belt")
	{
		result = eTrackIndex::TUCKED_BELT;
	}
	if (aTrackName == "top_a_belt")
	{
		result = eTrackIndex::TOP_A_BELT;
	}
	if (aTrackName == "belt_squash")
	{
		result = eTrackIndex::BELT_SQUASH;
	}
	else if (aTrackName == "bag")
	{
		result = eTrackIndex::BAG;
	}
	else if (aTrackName == "hat_low")
	{
		result = eTrackIndex::HAT_LOW;
	}
	else if (aTrackName == "hat_high")
	{
		result = eTrackIndex::HAT_HIGH;
	}
	else if (aTrackName == "boots")
	{
		result = eTrackIndex::BOOTS;
	}
	else if (aTrackName == "ba_under_high")
	{
		result = eTrackIndex::BA_UNDER_HIGH;
	}
	else if (aTrackName == "ba_under_low")
	{
		result = eTrackIndex::BA_UNDER_LOW;
	}
	else if (aTrackName == "ba_belt")
	{
		result = eTrackIndex::BA_BELT;
	}
	else if (aTrackName == "hips")
	{
		result = eTrackIndex::HIPS;
	}
	else if (aTrackName == "shbag")
	{
		result = eTrackIndex::SHBAG;
	}
	else if (aTrackName == "top_under")
	{
		result = eTrackIndex::TOP_UNDER;
	}
	else if (aTrackName == "ur_squash")
	{
		result = eTrackIndex::UR_SQUASH;
	}
	else if (aTrackName == "scarf_a_squash")
	{
		result = eTrackIndex::SCARF_A_SQUASH;
	}
	else if (aTrackName == "scarf_a_under")
	{
		result = eTrackIndex::SCARF_A_UNDER;
	}
	else if (aTrackName == "scarf_ab_under")
	{
		result = eTrackIndex::SCARF_AB_UNDER;
	}
	else if (aTrackName == "scarf_over_a")
	{
		result = eTrackIndex::SCARF_OVER_A;
	}
	else if (aTrackName == "scarf_over_b")
	{
		result = eTrackIndex::SCARF_OVER_B;
	}
	else if (aTrackName == "scarf_over_c")
	{
		result = eTrackIndex::SCARF_OVER_C;
	}
	else if (aTrackName == "scarf_over_d")
	{
		result = eTrackIndex::SCARF_OVER_D;
	}
	else if (aTrackName == "scarf_over_e")
	{
		result = eTrackIndex::SCARF_OVER_E;
	}
	else if (aTrackName == "scarf_over_f")
	{
		result = eTrackIndex::SCARF_OVER_F;
	}
	else if (aTrackName == "h_030_g")
	{
		result = eTrackIndex::H_030_G;
	}
	else if (aTrackName == "h_060_g")
	{
		result = eTrackIndex::H_060_G;
	}
	else if (aTrackName == "h_067_g")
	{
		result = eTrackIndex::H_067_G;
	}
	else if (aTrackName == "h_068_g")
	{
		result = eTrackIndex::H_068_G;
	}
	else if (aTrackName == "pants_on")
	{
		result = eTrackIndex::PANTS_ON;
	}
	else if (aTrackName == "ba_under_max")
	{
		result = eTrackIndex::BA_UNDER_MAX;
	}
	else if (aTrackName == "sleeve_squash")
	{
		result = eTrackIndex::SLEEVE_SQUASH;
	}
	else if (aTrackName == "boot_squash")
	{
		result = eTrackIndex::BOOT_SQUASH;
	}
	else if (aTrackName == "socks_squash")
	{
		result = eTrackIndex::SOCKS_SQUASH;
	}
	else if (aTrackName == "pants_shorter")
	{
		result = eTrackIndex::PANTS_SHORTER;
	}
	else if (aTrackName == "pants_wider")
	{
		result = eTrackIndex::PANTS_WIDER;
	}
	else if (aTrackName == "belt_under")
	{
		result = eTrackIndex::BELT_UNDER;
	}
	else if (aTrackName == "socks_squash_small")
	{
		result = eTrackIndex::SOCKS_SQUASH_SMALL;
	}
	else if (aTrackName == "fashionista_glove")
	{
		result = eTrackIndex::FASHIONISTA_GLOVE;
	}
	else if (aTrackName == "ringer")
	{
		result = eTrackIndex::RINGER;
	}
	else if (aTrackName == "necklace_squash")
	{
		result = eTrackIndex::NECKLACE_SQUASH;
	}
	else if (aTrackName == "glove_squash")
	{
		result = eTrackIndex::GLOVE_SQUASH;
	}
	else if (aTrackName == "reduce_necklace")
	{
		result = eTrackIndex::REDUCE_NECKLACE;
	}
	else if (aTrackName == "top_vest")
	{
		result = eTrackIndex::TOP_VEST;
	}
	else if (aTrackName == "tucked_suspender")
	{
		result = eTrackIndex::TUCKED_SUSPENDER;
	}
	else if (aTrackName == "makeup_1")
	{
		result = eTrackIndex::MAKEUP_1;
	}
	else if (aTrackName == "makeup_2")
	{
		result = eTrackIndex::MAKEUP_2;
	}
	else if (aTrackName == "makeup_3")
	{
		result = eTrackIndex::MAKEUP_3;
	}
	else if (aTrackName == "makeup_4")
	{
		result = eTrackIndex::MAKEUP_4;
	}
	else if (aTrackName == "makeup_5")
	{
		result = eTrackIndex::MAKEUP_5;
	}
	else if (aTrackName == "premium_1")
	{
		result = eTrackIndex::PREMIUM_1;
	}
	else if (aTrackName == "premium_2")
	{
		result = eTrackIndex::PREMIUM_2;
	}
	else if (aTrackName == "premium_3")
	{
		result = eTrackIndex::PREMIUM_3;
	}
	else if (aTrackName == "premium_4")
	{
		result = eTrackIndex::PREMIUM_4;
	}
	else if (aTrackName == "premium_5")
	{
		result = eTrackIndex::PREMIUM_5;
	}
	else if (aTrackName == "premium_6")
	{
		result = eTrackIndex::PREMIUM_6;
	}
	else if (aTrackName == "premium_7")
	{
		result = eTrackIndex::PREMIUM_7;
	}
	else if (aTrackName == "premium_8")
	{
		result = eTrackIndex::PREMIUM_8;
	}
	else if (aTrackName == "premium_9")
	{
		result = eTrackIndex::PREMIUM_9;
	}
	else if (aTrackName == "premium_10")
	{
		result = eTrackIndex::PREMIUM_10;
	}
	else if (aTrackName == "premium_11")
	{
		result = eTrackIndex::PREMIUM_11;
	}

	return result;
}

BValue DataTypesHelper::convertCharStyleToBValue(const sCharStyleInfo& aCharStyleRaw)
{
	BValueMap result;

	//result["skin_id"] = aCharStyleRaw.customizeInfo.skin_id;
	auto it = aCharStyleRaw.customizeInfo.skin_id.find("_");
	if (it != std::string::npos)
	{
		result["skin"] = aCharStyleRaw.customizeInfo.skin_id.substr( it + 1 );
	}

	BValueVector values;
	std::string strValues;
	BValue lookStrValue;

	for (auto& lookInfoPair : aCharStyleRaw.looks)
	{
		auto lookInfo = DM->getUnlockedLookInfo(lookInfoPair.second);
		if (lookInfo)
		{
			lookStrValue.initWithFormat("%d|%s", lookInfoPair.first, lookInfo->metaData.lookID.c_str());
			values.push_back( lookStrValue.getString() );
		}
	}
	result["looks"] = values;

	strValues.clear();
	eCharFacePart curType = eCharFacePart::UNDEFINED;
	while (curType != eCharFacePart::END)
	{
		auto facePartIt = aCharStyleRaw.customizeInfo.faceParts.find(curType);
		if (facePartIt != aCharStyleRaw.customizeInfo.faceParts.end())
		{
			if (!strValues.empty())
			{
				strValues.append("|");
			}
			strValues.append(facePartIt->second);
		}
		else
		{
			if (!strValues.empty())
			{
				strValues.append("|");
			}
		}

		int curTypeNumber = static_cast<int>(curType);
		++curTypeNumber;

		curType = static_cast<eCharFacePart>(curTypeNumber);
	}
	result["face"] = BValue(strValues);

	strValues.clear();
	eCharColorizedPart curColorType = eCharColorizedPart::UNDEFINED;
	while (curColorType != eCharColorizedPart::END)
	{
		auto colorPartIt = aCharStyleRaw.customizeInfo.colorParts.find(curColorType);
		if (colorPartIt != aCharStyleRaw.customizeInfo.colorParts.end())
		{
			std::string colorIndex = DM->getCharPartColorIndexByColor(curColorType, colorPartIt->second);

			if (!strValues.empty())
			{
				strValues.append("|");
			}

			strValues.append(colorIndex);
		}

		int curTypeNumber = static_cast<int>(curColorType);
		++curTypeNumber;

		curColorType = static_cast<eCharColorizedPart>(curTypeNumber);
	}

	result["colors"] = BValue(strValues);

	// ???
	if ( !aCharStyleRaw.customizeInfo.isHairEndsEnabled )
	{
		result["is_hair_ends_enabled"] = aCharStyleRaw.customizeInfo.isHairEndsEnabled;
	}

	return result;
}

void DataTypesHelper::serializeBValueToEventInfo(sEventInfo& aEvInfo, const BValue& aEvInfoRaw)
{
	auto& evInfoValueMap = aEvInfoRaw.getValueMap();

	auto evInfoValueMapItr = evInfoValueMap.find("event_id");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.eventUniqueID = evInfoValueMapItr->second.getString();
	}

	evInfoValueMapItr = evInfoValueMap.find("event_type");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.eventType = getEventTypeFromStr(evInfoValueMapItr->second.getString());
	}

	evInfoValueMapItr = evInfoValueMap.find("event_title_id");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.titleID = evInfoValueMapItr->second.getString();
	}

	evInfoValueMapItr = evInfoValueMap.find("desc_template_id");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.descTemplateID = evInfoValueMapItr->second.getString();
	}

	evInfoValueMapItr = evInfoValueMap.find("action_id");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.actionID = evInfoValueMapItr->second.getString();
	}

	evInfoValueMapItr = evInfoValueMap.find("style_id");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.styleID = evInfoValueMapItr->second.getString();
	}

	evInfoValueMapItr = evInfoValueMap.find("start_time");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.startTime = SceneHelper::convertStringToULong(evInfoValueMapItr->second.getString());
	}

	evInfoValueMapItr = evInfoValueMap.find("vote_time");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.votingTime = SceneHelper::convertStringToULong(evInfoValueMapItr->second.getString());
	}

	evInfoValueMapItr = evInfoValueMap.find("end_time");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.endTime = SceneHelper::convertStringToULong(evInfoValueMapItr->second.getString());
	}

	evInfoValueMapItr = evInfoValueMap.find("visibility");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.eventVisibility = DataTypesHelper::getEventVisibilityFromStr(evInfoValueMapItr->second.getString());
	}

	evInfoValueMapItr = evInfoValueMap.find("quality_id");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		for ( auto& evQualityIdItr : evInfoValueMapItr->second.getValueVector() )
		{
			aEvInfo.qualityIDs.push_back(evQualityIdItr.getString());
		}
	}

	evInfoValueMapItr = evInfoValueMap.find("event_rewards");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		for ( auto& evRewardItr : evInfoValueMapItr->second.getValueVector() )
		{
			aEvInfo.rewards.push_back(serializeBValueToEventRewardInfo(evRewardItr));
		}
	}

	evInfoValueMapItr = evInfoValueMap.find("event_requirements");

	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		for ( auto& evReqItr : evInfoValueMapItr->second.getValueVector() )
		{
			aEvInfo.requirements.push_back(serializeBValueToEventRequirementInfo(evReqItr));
		}
	}

	evInfoValueMapItr = evInfoValueMap.find("event_difficulty");
	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.eventDifficulty = getEventDifficultyFromStr(evInfoValueMapItr->second.getString());
	}

	evInfoValueMapItr = evInfoValueMap.find("entry_reward_amount");
	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.entryRewardAmount = evInfoValueMapItr->second.getInt();
	}

	evInfoValueMapItr = evInfoValueMap.find("entry_reward_type");
	if ( evInfoValueMapItr != evInfoValueMap.end() )
	{
		aEvInfo.entryRewardType = getEventRewardTypeFromString(evInfoValueMapItr->second.getString());
	}

	// TODO: maybe add support of vote_template_id, intro_id, voting_intro_id or find out whether they still needed in code
}

sVotingLookInfo DataTypesHelper::serializeBValueToVotingLookInfo(const BValue& aLookInfoRaw)
{
	sVotingLookInfo result;

	if ( aLookInfoRaw.checkType(BValue::Type::MAP) )
	{
		const BValueMap& lookInfoMap = aLookInfoRaw.getValueMap();

		auto mapItr = lookInfoMap.find("event_id");

		if ( mapItr != lookInfoMap.end() )
		{
			result.eventUniqueId = mapItr->second.getString();
		}

		mapItr = lookInfoMap.find("look");

		if ( mapItr != lookInfoMap.end() )
		{
			DataTypesHelper::parsePlayerStyleInfoFromBValue(mapItr->second, result.styleInfo);
		}

		mapItr = lookInfoMap.find("location_id");

		if ( mapItr != lookInfoMap.end() )
		{
			result.locationId = mapItr->second.getString();
		}

		mapItr = lookInfoMap.find("look_id");

		if ( mapItr != lookInfoMap.end() )
		{
			result.lookUniqueId = mapItr->second.getString();
		}

		mapItr = lookInfoMap.find("player_id");

		if ( mapItr != lookInfoMap.end() )
		{
			result.lookOwnerId = mapItr->second.getString();
		}

		mapItr = lookInfoMap.find("basket_id");

		if ( mapItr != lookInfoMap.end() )
		{
			result.basketId = mapItr->second.getString();
		}
	}
	return result;
}

void DataTypesHelper::serializeEventRequirementInfoToBValue(const sEventRequirementInfo* aEeqRaw, BValueMap& aInfo)
{
	std::string undefinedStr = "UNDEFINED";
	std::string filter = getStrFromLookFilterColor(static_cast<eLookFilterColor>(DataHelper::log2(aEeqRaw->lfilterColor)));
	if (filter != undefinedStr && !filter.empty())
	{
		aInfo["filter_color"] = filter;
	}

	filter = getStrFromLookFilterStyle(static_cast<eLookFilterStyle>(DataHelper::log2(aEeqRaw->lfilterStyle)));
	if (filter != undefinedStr && !filter.empty())
	{
		aInfo["filter_style"] = filter;
	}

	filter = getStrFromLookType(aEeqRaw->lookType);
	if (filter != undefinedStr && !filter.empty())
	{
		aInfo["look_category"] = filter;
	}

	filter = getStrFromLookFilterFabric(static_cast<eLookFilterFabric>(DataHelper::log2(aEeqRaw->lfilterFabric)));
	if (filter != undefinedStr && !filter.empty())
	{
		aInfo["filter_fabric"] = filter;
	}

	filter = getStrFromLookFilterPattern(static_cast<eLookFilterPattern>(DataHelper::log2(aEeqRaw->lfilterPattern)));
	if (filter != undefinedStr && !filter.empty())
	{
		aInfo["filter_pattern"] = filter;
	}

	if (aEeqRaw->lookSet != undefinedStr &&  !aEeqRaw->lookSet.empty())
	{
		aInfo["look_set"] = aEeqRaw->lookSet;
	}

	filter = getStrFromLookCustomFilter(aEeqRaw->lookType, DataHelper::log2(aEeqRaw->lfilterCustom));
	if (filter != undefinedStr && !filter.empty())
	{
		aInfo["filter_custom"] = filter;
	}
}



sEventRequirementInfo DataTypesHelper::serializeBValueToEventRequirementInfo(const BValue& aEvReqRaw)
{
	sEventRequirementInfo result;

	auto lookCategory = eLookCategory::UNDEFINED;

	auto& evRequirementsRawMap = aEvReqRaw.getValueMap();

	auto evRequirementsRawItr = evRequirementsRawMap.find("filter_color");

	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		result.lfilterColor = 1 << static_cast<int>( DataTypesHelper::getLookFilterColorFromStr(evRequirementsRawItr->second.getString()) );
	}

	evRequirementsRawItr = evRequirementsRawMap.find( "filter_style" );
	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		result.lfilterStyle = 1 << static_cast< int >( DataTypesHelper::getLookFilterStyleFromStr( evRequirementsRawItr->second.getString() ) );
	}

	evRequirementsRawItr = evRequirementsRawMap.find("look_category");

	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		lookCategory = getLookCategoryFromStr(evRequirementsRawItr->second.getString());

		result.lookType = getLookTypeFromStr(evRequirementsRawItr->second.getString());
	}

	evRequirementsRawItr = evRequirementsRawMap.find("filter_fabric");

	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		result.lfilterFabric = 1 << static_cast<int>( DataTypesHelper::getLookFilterFabricFromStr(evRequirementsRawItr->second.getString()) );
	}

	evRequirementsRawItr = evRequirementsRawMap.find("filter_pattern");

	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		result.lfilterPattern = 1 << static_cast<int>( DataTypesHelper::getLookFilterPatternFromStr( evRequirementsRawItr->second.getString() ) );
	}

	// TODO: check for possible drawbacks when got from server any look set requirement (compare it with lockal version parse)
	evRequirementsRawItr = evRequirementsRawMap.find("look_set");

	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		result.lookSet = evRequirementsRawItr->second.getString();
	}

	evRequirementsRawItr = evRequirementsRawMap.find("filter_custom");

	if ( evRequirementsRawItr != evRequirementsRawMap.end() )
	{
		if ( lookCategory == eLookCategory::DRESS )
		{
			if ( evRequirementsRawItr != evRequirementsRawMap.end() )
			{
				result.lfilterCustom = 1 << static_cast<int>( DataTypesHelper::getLookCustomFilterDressFromStr(evRequirementsRawItr->second.getString()) );
			}
		}
		else if ( lookCategory == eLookCategory::TOP_A )
		{
			if ( evRequirementsRawItr != evRequirementsRawMap.end() )
			{
				result.lfilterCustom = 1 << static_cast<int>( DataTypesHelper::getLookCustomFilterTopAFromStr(evRequirementsRawItr->second.getString()) );
			}
		}
		else if ( lookCategory == eLookCategory::TOP_B )
		{
			if ( evRequirementsRawItr != evRequirementsRawMap.end() )
			{
				result.lfilterCustom = 1 << static_cast<int>( DataTypesHelper::getLookCustomFilterTopBFromStr(evRequirementsRawItr->second.getString()) );
			}
		}
		else if ( lookCategory == eLookCategory::BOTTOM )
		{
			if ( evRequirementsRawItr != evRequirementsRawMap.end() )
			{
				result.lfilterCustom = 1 << static_cast<int>( DataTypesHelper::getLookCustomFilterBottomFromStr(evRequirementsRawItr->second.getString()) );
			}
		}
		else if ( lookCategory == eLookCategory::SHOES )
		{
			if ( evRequirementsRawItr != evRequirementsRawMap.end() )
			{
				result.lfilterCustom = 1 << static_cast<int>( DataTypesHelper::getLookCustomFilterShoesFromStr(evRequirementsRawItr->second.getString()) );
			}
		}
		else if ( lookCategory == eLookCategory::ACCESSORIES )
		{
			if ( evRequirementsRawItr != evRequirementsRawMap.end() )
			{
				eLookCustomFilterAccessories accType = DataTypesHelper::getLookCustomFilterAccessoriesFromStr(evRequirementsRawItr->second.getString());

				switch ( accType ) {
					case eLookCustomFilterAccessories::HAT:
						result.lookType = eLookType::ACC_HATS;
						break;
					case eLookCustomFilterAccessories::GLASSES:
						result.lookType = eLookType::ACC_GLASSES;
						break;
					case eLookCustomFilterAccessories::JEWELRY:
						result.lookType = eLookType::ACC_JEWELRY;
						break;
					case eLookCustomFilterAccessories::BELT:
						result.lookType = eLookType::ACC_BELTS;
						break;
					case eLookCustomFilterAccessories::GLOVES:
						result.lookType = eLookType::ACC_GLOVES;
						break;
					case eLookCustomFilterAccessories::BAG:
						result.lookType = eLookType::ACC_HANDBAGS;
						break;
					case eLookCustomFilterAccessories::SCARF:
						result.lookType = eLookType::ACC_SCARVES;
						break;
					case eLookCustomFilterAccessories::BROOCH:
						result.lookType = eLookType::ACC_BROOCH;
						break;
					case eLookCustomFilterAccessories::STOCKINGS:
						result.lookType = eLookType::ACC_STOCKINGS;
						break;
					default:
						result.lookType = eLookType::UNDEFINED;
						break;
				}

				result.lfilterCustom = 1 << static_cast<int>( accType );
			}
		}
	}

	return result;
}

void DataTypesHelper::parseEventRequirementInfoFromRapidjsonValue(sEventRequirementInfo& aEvReqInfo, const rapidjson::Value& aRapidjsonValue)
{
	auto lookCategory = eLookCategory::UNDEFINED;

	if (aRapidjsonValue.HasMember( "filter_color" ))
	{
		aEvReqInfo.lfilterColor = 1 << static_cast<int>(DataTypesHelper::getLookFilterColorFromStr(aRapidjsonValue[ "filter_color" ].GetString()));
	}

	if (aRapidjsonValue.HasMember("filter_style"))
	{
		aEvReqInfo.lfilterStyle = 1 << static_cast<int>(DataTypesHelper::getLookFilterStyleFromStr(aRapidjsonValue["filter_style"].GetString()));
	}

	if (aRapidjsonValue.HasMember("look_category"))
	{
		auto lookCategoryStr = aRapidjsonValue["look_category"].GetString();

		lookCategory = getLookCategoryFromStr( lookCategoryStr );
		aEvReqInfo.lookType = getLookTypeFromStr( lookCategoryStr );
	}

	if (aRapidjsonValue.HasMember("filter_fabric"))
	{
		aEvReqInfo.lfilterFabric = 1 << static_cast<int>(DataTypesHelper::getLookFilterFabricFromStr(aRapidjsonValue["filter_fabric"].GetString()));
	}

	if (aRapidjsonValue.HasMember("filter_pattern"))
	{
		aEvReqInfo.lfilterPattern = 1 << static_cast<int>(DataTypesHelper::getLookFilterPatternFromStr(aRapidjsonValue["filter_pattern"].GetString()));
	}

	if (aRapidjsonValue.HasMember("look_set"))
	{
		aEvReqInfo.lookSet = aRapidjsonValue["look_set"].GetString();
	}

	if (aRapidjsonValue.HasMember("filter_custom"))
	{
		auto filterCustomStr = aRapidjsonValue["filter_custom"].GetString();
		if (lookCategory == eLookCategory::DRESS)
		{
			aEvReqInfo.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterDressFromStr( filterCustomStr ));
		}
		else if (lookCategory == eLookCategory::TOP_A)
		{
			aEvReqInfo.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterTopAFromStr(filterCustomStr));
		}
		else if (lookCategory == eLookCategory::TOP_B)
		{
			aEvReqInfo.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterTopBFromStr(filterCustomStr));
		}
		else if (lookCategory == eLookCategory::BOTTOM)
		{
			aEvReqInfo.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterBottomFromStr(filterCustomStr));
		}
		else if (lookCategory == eLookCategory::SHOES)
		{
			aEvReqInfo.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterShoesFromStr(filterCustomStr));
		}
		else if (lookCategory == eLookCategory::ACCESSORIES)
		{
			eLookCustomFilterAccessories accType = DataTypesHelper::getLookCustomFilterAccessoriesFromStr(filterCustomStr);

			switch (accType) {
			case eLookCustomFilterAccessories::HAT:
				aEvReqInfo.lookType = eLookType::ACC_HATS;
				break;
			case eLookCustomFilterAccessories::GLASSES:
				aEvReqInfo.lookType = eLookType::ACC_GLASSES;
				break;
			case eLookCustomFilterAccessories::JEWELRY:
				aEvReqInfo.lookType = eLookType::ACC_JEWELRY;
				break;
			case eLookCustomFilterAccessories::BELT:
				aEvReqInfo.lookType = eLookType::ACC_BELTS;
				break;
			case eLookCustomFilterAccessories::GLOVES:
				aEvReqInfo.lookType = eLookType::ACC_GLOVES;
				break;
			case eLookCustomFilterAccessories::BAG:
				aEvReqInfo.lookType = eLookType::ACC_HANDBAGS;
				break;
			case eLookCustomFilterAccessories::SCARF:
				aEvReqInfo.lookType = eLookType::ACC_SCARVES;
				break;
			case eLookCustomFilterAccessories::BROOCH:
				aEvReqInfo.lookType = eLookType::ACC_BROOCH;
				break;
			case eLookCustomFilterAccessories::STOCKINGS:
				aEvReqInfo.lookType = eLookType::ACC_STOCKINGS;
				break;
			default:
				aEvReqInfo.lookType = eLookType::UNDEFINED;
				break;
			}

			aEvReqInfo.lfilterCustom = 1 << static_cast<int>(accType);
		}
	}
}

void DataTypesHelper::parseEventInfoFromJsonValue(sEventInfo & aEvInfo, const rapidjson::Value & aRapidjsonValue)
{
	if (aRapidjsonValue.IsObject())
	{
		if (aRapidjsonValue.HasMember("metric_num_id") && aRapidjsonValue["metric_num_id"].IsString())
		{
			aEvInfo.liveOpsMetricID = aRapidjsonValue["metric_num_id"].GetString();
		}

		if (aRapidjsonValue.HasMember("event_id") && aRapidjsonValue["event_id"].IsString())
		{
			aEvInfo.eventUniqueID = aRapidjsonValue["event_id"].GetString();
		}

		if (aRapidjsonValue.HasMember("event_type") && aRapidjsonValue["event_type"].IsString())
		{
			aEvInfo.eventType = getEventTypeFromStr(aRapidjsonValue["event_type"].GetString());
		}

		if (aRapidjsonValue.HasMember("event_title_id") && aRapidjsonValue["event_title_id"].IsString())
		{
			aEvInfo.titleID = aRapidjsonValue["event_title_id"].GetString();
		}

		if (aRapidjsonValue.HasMember("desc_template_id") && aRapidjsonValue["desc_template_id"].IsString())
		{
			aEvInfo.descTemplateID = aRapidjsonValue["desc_template_id"].GetString();
		}

		if (aRapidjsonValue.HasMember("action_id") && aRapidjsonValue["action_id"].IsString())
		{
			aEvInfo.actionID = aRapidjsonValue["action_id"].GetString();
		}

		if (aRapidjsonValue.HasMember("style_id") && aRapidjsonValue["style_id"].IsString())
		{
			aEvInfo.styleID = aRapidjsonValue["style_id"].GetString();
		}

		if (aRapidjsonValue.HasMember("start_time") && aRapidjsonValue["start_time"].IsString())
		{
			aEvInfo.startTime = SceneHelper::convertStringToULong( aRapidjsonValue["start_time"].GetString());
		}

		if (aRapidjsonValue.HasMember("vote_time") && aRapidjsonValue["vote_time"].IsString())
		{
			aEvInfo.votingTime = SceneHelper::convertStringToULong( aRapidjsonValue["vote_time"].GetString());
		}

		if (aRapidjsonValue.HasMember("end_time") && aRapidjsonValue["end_time"].IsString())
		{
			aEvInfo.endTime =  SceneHelper::convertStringToULong( aRapidjsonValue["end_time"].GetString());
		}

		if (aRapidjsonValue.HasMember("visibility") && aRapidjsonValue["visibility"].IsString())
		{
			aEvInfo.eventVisibility = DataTypesHelper::getEventVisibilityFromStr(aRapidjsonValue["visibility"].GetString());
		}

		if (aRapidjsonValue.HasMember("quality_id") && aRapidjsonValue["quality_id"].IsArray())
		{
			auto qualityArray = aRapidjsonValue["quality_id"].GetArray();
			for (auto& evQualityIdItr : qualityArray)
			{
				if (evQualityIdItr.IsString())
				{
					aEvInfo.qualityIDs.push_back(evQualityIdItr.GetString());
				}
			}
		}

		if (aRapidjsonValue.HasMember("event_rewards") && aRapidjsonValue["event_rewards"].IsArray())
		{
			auto rewardsArray = aRapidjsonValue["event_rewards"].GetArray();
			for (auto& rewardItr : rewardsArray)
			{
				if (rewardItr.IsObject())
				{
					sEventRewardInfo info;
					DataTypesHelper::parseEventRewardInfo(rewardItr, info);
					aEvInfo.rewards.push_back(info);
				}
			}
		}

		if (aRapidjsonValue.HasMember("event_requirements") && aRapidjsonValue["event_requirements"].IsArray())
		{
			auto requirementsArray = aRapidjsonValue["event_requirements"].GetArray();

			for (auto& evReqItr : requirementsArray)
			{
				aEvInfo.requirements.push_back(parseEventRequirementInfoFromJsonValue(evReqItr));
			}
		}

		if (aRapidjsonValue.HasMember("event_difficulty") && aRapidjsonValue["event_difficulty"].IsString())
		{
			aEvInfo.eventDifficulty = getEventDifficultyFromStr(aRapidjsonValue["event_difficulty"].GetString());
		}

		if (aRapidjsonValue.HasMember("entry_reward_amount") && aRapidjsonValue["entry_reward_amount"].IsString())
		{
			aEvInfo.entryRewardAmount = std::stoi(aRapidjsonValue["entry_reward_amount"].GetString());
		}

		if (aRapidjsonValue.HasMember("entry_reward_type") && aRapidjsonValue["entry_reward_type"].IsString())
		{
			aEvInfo.entryRewardType = getEventRewardTypeFromString(aRapidjsonValue["entry_reward_type"].GetString());
		}
	}
}


sEventRequirementInfo DataTypesHelper::parseEventRequirementInfoFromJsonValue(const rapidjson::Value & aRapidjsonValue)
{
	sEventRequirementInfo result;

	if (aRapidjsonValue.IsObject())
	{
		auto lookCategory = eLookCategory::UNDEFINED;

		if (aRapidjsonValue.HasMember("filter_color") && aRapidjsonValue["filter_color"].IsString())
		{
			result.lfilterColor = 1 << static_cast<int>(DataTypesHelper::getLookFilterColorFromStr(aRapidjsonValue["filter_color"].GetString()));
		}

		if (aRapidjsonValue.HasMember("filter_style") && aRapidjsonValue["filter_style"].IsString())
		{
			result.lfilterStyle = 1 << static_cast<int>(DataTypesHelper::getLookFilterStyleFromStr(aRapidjsonValue["filter_style"].GetString()));
		}

		if (aRapidjsonValue.HasMember("look_category") && aRapidjsonValue["look_category"].IsString())
		{
			lookCategory = getLookCategoryFromStr(aRapidjsonValue["look_category"].GetString());

			result.lookType = getLookTypeFromStr(aRapidjsonValue["look_category"].GetString());
		}

		if (aRapidjsonValue.HasMember("filter_fabric") && aRapidjsonValue["filter_fabric"].IsString())
		{
			result.lfilterFabric = 1 << static_cast<int>(DataTypesHelper::getLookFilterFabricFromStr(aRapidjsonValue["filter_fabric"].GetString()));
		}

		if (aRapidjsonValue.HasMember("filter_pattern") && aRapidjsonValue["filter_pattern"].IsString())
		{
			result.lfilterPattern = 1 << static_cast<int>(DataTypesHelper::getLookFilterPatternFromStr(aRapidjsonValue["filter_pattern"].GetString()));
		}


		if (aRapidjsonValue.HasMember("look_set") && aRapidjsonValue["look_set"].IsString())
		{
			result.lookSet = aRapidjsonValue["look_set"].GetString();
		}

		if (aRapidjsonValue.HasMember("filter_custom") && aRapidjsonValue["filter_custom"].IsString())
		{
			if (lookCategory == eLookCategory::DRESS)
			{
					result.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterDressFromStr(aRapidjsonValue["filter_custom"].GetString()));
			}
			else if (lookCategory == eLookCategory::TOP_A)
			{
					result.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterTopAFromStr(aRapidjsonValue["filter_custom"].GetString()));
			}
			else if (lookCategory == eLookCategory::TOP_B)
			{
					result.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterTopBFromStr(aRapidjsonValue["filter_custom"].GetString()));
			}
			else if (lookCategory == eLookCategory::BOTTOM)
			{
					result.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterBottomFromStr(aRapidjsonValue["filter_custom"].GetString()));
			}
			else if (lookCategory == eLookCategory::SHOES)
			{
					result.lfilterCustom = 1 << static_cast<int>(DataTypesHelper::getLookCustomFilterShoesFromStr(aRapidjsonValue["filter_custom"].GetString()));
			}
			else if (lookCategory == eLookCategory::ACCESSORIES)
			{
				eLookCustomFilterAccessories accType = DataTypesHelper::getLookCustomFilterAccessoriesFromStr(aRapidjsonValue["filter_custom"].GetString());

				switch (accType) {
				case eLookCustomFilterAccessories::HAT:
					result.lookType = eLookType::ACC_HATS;
					break;
				case eLookCustomFilterAccessories::GLASSES:
					result.lookType = eLookType::ACC_GLASSES;
					break;
				case eLookCustomFilterAccessories::JEWELRY:
					result.lookType = eLookType::ACC_JEWELRY;
					break;
				case eLookCustomFilterAccessories::BELT:
					result.lookType = eLookType::ACC_BELTS;
					break;
				case eLookCustomFilterAccessories::GLOVES:
					result.lookType = eLookType::ACC_GLOVES;
					break;
				case eLookCustomFilterAccessories::BAG:
					result.lookType = eLookType::ACC_HANDBAGS;
					break;
				case eLookCustomFilterAccessories::SCARF:
					result.lookType = eLookType::ACC_SCARVES;
					break;
				case eLookCustomFilterAccessories::BROOCH:
					result.lookType = eLookType::ACC_BROOCH;
					break;
				case eLookCustomFilterAccessories::STOCKINGS:
					result.lookType = eLookType::ACC_STOCKINGS;
					break;
				default:
					result.lookType = eLookType::UNDEFINED;
					break;
				}

				result.lfilterCustom = 1 << static_cast<int>(accType);
			}
		}
	}

	return result;
}

eMinigameCharacterType DataTypesHelper::getMinigameCharaterTypeFromStr(const std::string& aStr)
{
	eMinigameCharacterType result = eMinigameCharacterType::UNDEFINED;

	if (aStr == "BARISTA")
	{
		result = eMinigameCharacterType::BARISTA;
	}
	else if (aStr == "CRITIC")
	{
		result = eMinigameCharacterType::CRITIC;
	}
	else if (aStr == "DJ")
	{
		result = eMinigameCharacterType::DJ;
	}
	else if (aStr == "CEO")
	{
		result = eMinigameCharacterType::CEO;
	}
	else if (aStr == "FITMOM")
	{
		result = eMinigameCharacterType::FITMOM;
	}

	return result;
}

sEventRewardInfo DataTypesHelper::serializeBValueToEventRewardInfo(const BValue& aEvRewardRaw)
{
	sEventRewardInfo result;

	auto& evRewardsRawMap = aEvRewardRaw.getValueMap();

	auto evRewardMapItr = evRewardsRawMap.find("required_stars");

	if ( evRewardMapItr != evRewardsRawMap.end() )
	{
		result.requiredStarsCount = std::atoi(evRewardMapItr->second.getString().c_str());
	}

	evRewardMapItr = evRewardsRawMap.find("reward_amount");

	if ( evRewardMapItr != evRewardsRawMap.end() )
	{
		result.rewardsAmount = std::atoi(evRewardMapItr->second.getString().c_str());
	}

	evRewardMapItr = evRewardsRawMap.find("reward_look_id");

	if ( evRewardMapItr != evRewardsRawMap.end() )
	{
		result.rewardLookId = evRewardMapItr->second.getString();
	}

	evRewardMapItr = evRewardsRawMap.find("reward_type");

	if ( evRewardMapItr != evRewardsRawMap.end() )
	{
		result.rewardType = getEventRewardTypeFromString(evRewardMapItr->second.getString());
	}

	return result;
}

std::string DataTypesHelper::getStringFromMinigameCharacterType(eMinigameCharacterType aType)
{
	std::string result;

	switch ( aType ) {
		case eMinigameCharacterType::BARISTA:
			result = "BARISTA";
			break;
		case eMinigameCharacterType::CRITIC:
			result = "CRITIC";
			break;
		case eMinigameCharacterType::DJ:
			result = "DJ";
			break;
		case eMinigameCharacterType::CEO:
			result = "CEO";
			break;
		case eMinigameCharacterType::FITMOM:
			result = "FITMOM";
			break;

		default:
			break;
	}

	return result;
}

eLeaderboardRank DataTypesHelper::getLeaderboardRankFormStr(const std::string & aStr)
{
	eLeaderboardRank result = eLeaderboardRank::UNDEFINED;

	if ( aStr == "A_PLUS" )
	{
		result = eLeaderboardRank::A_PLUS;
	}
	else if ( aStr == "A" )
	{
		result = eLeaderboardRank::A;
	}
	else if ( aStr == "B" )
	{
		result = eLeaderboardRank::B;
	}
	else if ( aStr == "C" )
	{
		result = eLeaderboardRank::C;
	}
	else if ( aStr == "D" )
	{
		result = eLeaderboardRank::D;
	}
	else if (aStr == "E")
	{
		result = eLeaderboardRank::E;
	}

	return result;
}

std::string DataTypesHelper::getStringFromLeaderboardRank(eLeaderboardRank aRank)
{
	std::string result;

	switch ( aRank )
	{
		case cocos2d::eLeaderboardRank::UNDEFINED:
			break;
		case cocos2d::eLeaderboardRank::A_PLUS:
			result = "A+";
			break;
		case cocos2d::eLeaderboardRank::A:
			result = "A";
			break;
		case cocos2d::eLeaderboardRank::B:
			result = "B";
			break;
		case cocos2d::eLeaderboardRank::C:
			result = "C";
			break;
		case cocos2d::eLeaderboardRank::D:
			result = "D";
			break;
		case cocos2d::eLeaderboardRank::E:
			result = "E";
			break;
		case cocos2d::eLeaderboardRank::ENUM_BORDER:
			break;
		default:
			break;
	}
	return result;
}

eLootBoxPoolType DataTypesHelper::getLootBoxPoolTypeFromStr(const std::string& aStr)
{
	eLootBoxPoolType result = eLootBoxPoolType::UNDEFINED;

	if ( aStr == "BASIC" )
	{
		result = eLootBoxPoolType::BASIC;
	}
	else if ( aStr == "SIMPLE" )
	{
		result = eLootBoxPoolType::SIMPLE;
	}
	else if ( aStr == "MEDIUM" )
	{
		result = eLootBoxPoolType::MEDIUM;
	}
	else if ( aStr == "TOP" )
	{
		result = eLootBoxPoolType::TOP;
	}
	else if (aStr == "SPECIAL")
	{
		result = eLootBoxPoolType::SPECIAL;
	}

	return result;
}

std::string DataTypesHelper::getStrFromLootBoxPoolType(eLootBoxPoolType aEnum)
{
	std::string retVal;

	switch ( aEnum )
	{
		case eLootBoxPoolType::UNDEFINED:
			retVal = "UNDEFINED";
			break;
		case eLootBoxPoolType::BASIC:
			retVal = "BASIC";
			break;
		case eLootBoxPoolType::SIMPLE:
			retVal = "SIMPLE";
			break;
		case eLootBoxPoolType::MEDIUM:
			retVal = "MEDIUM";
			break;
		case eLootBoxPoolType::TOP:
			retVal = "TOP";
			break;
		default:
			break;
	}

	return retVal;
}

unsigned DataTypesHelper::getIntFromCustomFilterString(const std::string& aRawStr)
{
	unsigned result = 0;

	int shiftLength = 0;

	eLookCustomFilterDress filter = DataTypesHelper::getLookCustomFilterDressFromStr(aRawStr);

	if ( filter != eLookCustomFilterDress::UNDEFINED )
	{
		shiftLength = static_cast<int>( filter );
	}

	if ( !shiftLength )
	{
		eLookCustomFilterTopA filter = DataTypesHelper::getLookCustomFilterTopAFromStr(aRawStr);

		if ( filter != eLookCustomFilterTopA::UNDEFINED )
		{
			shiftLength = static_cast<int>( filter );
		}
	}

	if ( !shiftLength )
	{
		eLookCustomFilterTopB filter = DataTypesHelper::getLookCustomFilterTopBFromStr(aRawStr);

		if ( filter != eLookCustomFilterTopB::UNDEFINED )
		{
			shiftLength = static_cast<int>( filter );
		}
	}

	if ( !shiftLength )
	{
		eLookCustomFilterBottom filter = DataTypesHelper::getLookCustomFilterBottomFromStr(aRawStr);

		if ( filter != eLookCustomFilterBottom::UNDEFINED )
		{
			shiftLength = static_cast<int>( filter );
		}
	}

	if ( !shiftLength )
	{
		eLookCustomFilterShoes filter = DataTypesHelper::getLookCustomFilterShoesFromStr(aRawStr);

		if ( filter != eLookCustomFilterShoes::UNDEFINED )
		{
			shiftLength = static_cast<int>( filter );
		}
	}

	if ( !shiftLength )
	{
		eLookCustomFilterAccessories accType = DataTypesHelper::getLookCustomFilterAccessoriesFromStr(aRawStr);

		if ( accType != eLookCustomFilterAccessories::UNDEFINED )
		{
			shiftLength = static_cast<int>( accType );
		}
	}

	result = 1 << shiftLength;

	return result;
}

sLeaderboardSeasonInfo DataTypesHelper::getLeaderboardSeasonInfoFromBValue(const BValue& aRawValue)
{
	sLeaderboardSeasonInfo result;

	if (aRawValue.checkType(BValue::Type::MAP))
	{
		const BValueMap& seasonDataMap = aRawValue.getValueMap();

		auto seasonDataMapItr = seasonDataMap.find("leaderTitle");

		if (seasonDataMapItr != seasonDataMap.end())
		{
			if (seasonDataMapItr->second.isMap())
			{
				const auto& titleMap = seasonDataMapItr->second.getValueMap();

				auto titleIt = titleMap.find("t");
				if (titleIt != titleMap.end())
				{
					result.titleId = titleIt->second.getString();
				}
				else
				{

					titleIt = titleMap.find("y");
					if (titleIt != titleMap.end())
					{
						result.year = titleIt->second.getInt();
					}

					titleIt = titleMap.find("w");
					if (titleIt != titleMap.end())
					{
						result.week = titleIt->second.getInt();
					}

					titleIt = titleMap.find("m");
					if (titleIt != titleMap.end())
					{
						result.monthId = titleIt->second.getInt();
					}

					result.titleId.clear();
				}
			}
			else if (seasonDataMapItr->second.isString())
			{
				result.titleId = seasonDataMapItr->second.getString();
			}
		}

		seasonDataMapItr = seasonDataMap.find("seasonID");

		if (seasonDataMapItr != seasonDataMap.end())
		{
			result.seasonUniqueId = seasonDataMapItr->second.getString();
		}

		seasonDataMapItr = seasonDataMap.find("startTime");

		if (seasonDataMapItr != seasonDataMap.end())
		{
			result.startTime = SceneHelper::convertStringToULong(seasonDataMapItr->second.getString());
		}

		seasonDataMapItr = seasonDataMap.find("endTime");

		if (seasonDataMapItr != seasonDataMap.end())
		{
			result.endTime = SceneHelper::convertStringToULong(seasonDataMapItr->second.getString());
		}
	}

	return result;
}

BValue DataTypesHelper::serializePlayerStyleToBValue(const sPlayerStyleInfo& aRawValue)
{
	BValueMap result;

	result["uid"] = aRawValue.uniqueID;
	result["eid"] = aRawValue.eventID;

	BValueVector bonuses;
	for ( auto& bonusInfoPair : aRawValue.lookBonuses )
	{
		if ( bonusInfoPair.second )
		{
			bonuses.push_back(static_cast<int>( bonusInfoPair.first ));
		}
	}

	result["lookInfo"] = convertCharStyleToBValue(aRawValue.playerStyle);

	result["bonuses"] = bonuses;

	float starsCountRounded = std::roundf( aRawValue.starsCount * 100.0f ) / 100.0f;

	std::stringstream stream;
	stream << std::fixed << std::setprecision( 2 ) << starsCountRounded;

	result["stars"] = stream.str();
	result["locId"] = aRawValue.locationID;
	result["score"] = aRawValue.influenceScore;

	result["v_time"] = aRawValue.endTime;
	result["s_time"] = aRawValue.submitTime;

	BValueVector likedBy;

	for ( auto& liker : aRawValue.likedBy )
	{
		likedBy.push_back(liker);
	}
	result["likedBy"] = likedBy;

	result["pid"] = aRawValue.ownerPlayerID;

	result["title"] = aRawValue.titleID;

	return result;
}

eLocationType DataTypesHelper::getLocationTypeFromString(const std::string& aStr)
{
	eLocationType result = eLocationType::UNDEFINED;

	if (aStr == "REGULAR")
	{
		result = eLocationType::REGULAR;
	}
	else if (aStr == "SPECIAL")
	{
		result = eLocationType::SPECIAL;
	}

	return result;
}


std::string DataTypesHelper::getRegularSeasonTitle(int aMonth, int aYear, int aWeek)
{
	BValue aStr;
	auto title = GET_STRING(LEADERBOARDS_MNG->getLeaderTitleId().c_str());
	auto month = GET_STRING(LEADERBOARDS_MNG->getMonthById(aMonth).c_str());
	aStr.initWithFormat(title.c_str(),
		month.c_str(),
		aWeek,
		aYear);
	return aStr.getString();
}

std::string DataTypesHelper::decodeLink(const std::string & aSrc)
{
	std::string decoded = aSrc;
	std::smatch sm;
	std::string haystack;

	int dynamicLength = decoded.size() - 2;

	if (decoded.size() < 3) return decoded;

	for (int i = 0; i < dynamicLength; i++)
	{
		haystack = decoded.substr(i, 3);

		if (std::regex_match(haystack, sm, std::regex("%[0-9A-F]{2}")))
		{
			haystack = haystack.replace(0, 1, "0x");
			std::string rc = { (char)std::stoi(haystack, nullptr, 16) };
			decoded = decoded.replace(decoded.begin() + i, decoded.begin() + i + 3, rc);
		}

		dynamicLength = decoded.size() - 2;
	}

	return decoded;
}

sDeepLinkInfo DataTypesHelper::parseDeepLinkInfoFromString(const std::string & aData)
{
	sDeepLinkInfo  result;
	std::string data = DataTypesHelper::decodeLink( aData );

    if (!data.empty())
    {
        std::map<std::string, sDeepLinkInfo> deepLinksInfo;
        deepLinksInfo["itemshop_screen"] = sDeepLinkInfo(eDeepLinkType::ITEM_SHOP, eDeepLinkOption::NONE, "");
        deepLinksInfo["itemshop_collection"] = sDeepLinkInfo(eDeepLinkType::ITEM_SHOP, eDeepLinkOption::COLLECTION_ITEMS, "");
        deepLinksInfo["itemshop_sale"] = sDeepLinkInfo(eDeepLinkType::ITEM_SHOP, eDeepLinkOption::SALE, "");
        deepLinksInfo["l30dr"] = sDeepLinkInfo(eDeepLinkType::COMEBACK, eDeepLinkOption::NONE, "");
        deepLinksInfo["iapshop_screen"] = sDeepLinkInfo(eDeepLinkType::IAP_SHOP, eDeepLinkOption::NONE, "");
        deepLinksInfo["iapshop_offer"] = sDeepLinkInfo(eDeepLinkType::IAP_SHOP, eDeepLinkOption::OFFER, "");
		deepLinksInfo["iapshop_packdeal"] = sDeepLinkInfo(eDeepLinkType::IAP_SHOP, eDeepLinkOption::PACKDEAL, "");
        deepLinksInfo["event"] = sDeepLinkInfo(eDeepLinkType::EVENT, eDeepLinkOption::EVENT, "");

        auto splitByQuestion = BCHelper::getSplitStringsVecWithSeparator(data, "?", false);
        if (splitByQuestion.size() > 1)
        {
            data = splitByQuestion[1];
        }

        auto dataVec = BCHelper::getSplitStringsVecWithSeparator(data, "&", false);
        for (auto& item : dataVec)
        {
            auto splitByEqual = BCHelper::getSplitStringsVecWithSeparator(item, "=", false);
            if (splitByEqual.size() == 2)
            {
                auto itItem = deepLinksInfo.find(splitByEqual[0]);
                if (itItem != deepLinksInfo.end())
                {
                    result = itItem->second;
                    result.parametr = splitByEqual[1];
                    break;
                }
            }
        }

    }
	return result;
}

void DataTypesHelper::parsePlayerInfoFromCDNFollowInfo(const BValue & aRawValue, sPlayerInfo& aInfo)
{
    if (aRawValue.checkType(BValue::Type::MAP))
    {
        const BValueMap& responceParamsMap = aRawValue.getValueMap();
        
        auto mapItr = responceParamsMap.find("_id");
        if (mapItr != responceParamsMap.end())
        {
            aInfo.playerID = mapItr->second.getString();
        }
        
        
        const BValue* data = nullptr;
        mapItr = responceParamsMap.find("data");
        if (mapItr != responceParamsMap.end())
        {
            data = &(mapItr->second);
        }
        else
        {
            data = &aRawValue;
        }
        
        if (data && data->checkType(BValue::Type::MAP))
        {
            const BValueMap& responceParamsMap = data->getValueMap();
            
            auto dataIt = responceParamsMap.find("nickname");
            if (dataIt != responceParamsMap.end())
            {
                if (dataIt->second.checkType(BValue::Type::STRING))
                {
                    aInfo.nickname = dataIt->second.getString();
                }
                aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::NICKNAME)] = true;
            }
            
            dataIt = responceParamsMap.find("avatar");
            if (dataIt != responceParamsMap.end())
            {
                DataTypesHelper::parseCharStyleInfoFromNetwork(dataIt->second,aInfo.avatar);
                aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::AVATAR)] = true;
            }
            
            dataIt = responceParamsMap.find("fb_id");
            if (dataIt != responceParamsMap.end() && dataIt->second.checkType(BValue::Type::STRING))
            {
                aInfo.fbId = dataIt->second.getString();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FB_ID)] = true;
            
            dataIt = responceParamsMap.find("is_following");
            if (dataIt != responceParamsMap.end() && dataIt->second.isBoolean())
            {
                if (dataIt->second.getBool())
                {
                    aInfo.followState = eFollowState::FOLLOWED;
                }
                else
                {
                    aInfo.followState = eFollowState::NOT_FOLLOWED;
                }
            }
            
            if (aInfo.followState != eFollowState::NONE)
            {
                aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FOLLOW_INFO)] = true;
            }
        }
    }
}

void DataTypesHelper::parsePlayerInfoFromBValue(const BValue & aRawValue, sPlayerInfo& aInfo)
{
	if (aRawValue.checkType(BValue::Type::MAP))
	{
		const BValueMap& responceParamsMap = aRawValue.getValueMap();

		auto mapItr = responceParamsMap.find("_id");
		if (mapItr != responceParamsMap.end())
		{
			aInfo.playerID = mapItr->second.getString();
		}

		const BValue* data = nullptr;
		mapItr = responceParamsMap.find("data");
		if (mapItr != responceParamsMap.end())
		{
			data = &(mapItr->second);
		}
		else
		{
			data = &aRawValue;
		}

		if (data && data->checkType(BValue::Type::MAP))
		{
			const BValueMap& responceParamsMap = data->getValueMap();

			auto dataIt = responceParamsMap.find("nickname");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::STRING))
				{
					aInfo.nickname = dataIt->second.getString();
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::NICKNAME)] = true;
			}

			dataIt = responceParamsMap.find("prev_season_best_look");
			if (dataIt != responceParamsMap.end())
			{
				DataTypesHelper::parsePlayerStyleInfoFromBValue(dataIt->second, aInfo.prevBestSeasonalLook);
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::PREV_BEST_SEASONAL_LOOK)] = true;
			}

			dataIt = responceParamsMap.find("avatar");
			if (dataIt != responceParamsMap.end())
			{
				DataTypesHelper::parseCharStyleInfoFromNetwork(dataIt->second,aInfo.avatar);
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::AVATAR)] = true;
			}

			dataIt = responceParamsMap.find("trends_set");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER))
				{
					aInfo.trendsSet = dataIt->second.getInt();
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::TRENDS_SET)] = true;
			}

			dataIt = responceParamsMap.find("badges");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER))
				{
					aInfo.badges = dataIt->second.getInt();
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::BADGES)] = true;
			}

			dataIt = responceParamsMap.find("badges_info");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::MAP))
				{
					auto& badgesMap = dataIt->second.getValueMap();
					for (auto& badgeIt : badgesMap)
					{
						aInfo.badgesInfo[badgeIt.first] = badgeIt.second.getInt();
					}
				}

				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::BADGES_INFO)] = true;
			}

			dataIt = responceParamsMap.find("experience");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER))
				{
					aInfo.experience = dataIt->second.getInt();
					aInfo.level = DM->convertExpToLevel(aInfo.experience, eLevelsType::PLAYER_LEVEL);
				}
				else
				{
					aInfo.level = DM->convertExpToLevel(aInfo.experience, eLevelsType::PLAYER_LEVEL);
				}

				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::EXPERIENCE)] = true;
			}

			dataIt = responceParamsMap.find("followers_count");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER)
					|| dataIt->second.checkType(BValue::Type::STRING))
				{
					aInfo.followersCount = dataIt->second.getInt();
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FOLLOWERS_COUNT)] = true;
			}

            dataIt = responceParamsMap.find("dts_item");
            if (dataIt != responceParamsMap.end())
            {
                if (dataIt->second.checkType(BValue::Type::STRING))
                {
                    aInfo.desTopSelItem = dataIt->second.getString();
                }
                aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_TOP_SEL_ITEM)] = true;
            }

			dataIt = responceParamsMap.find("is_bot");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER)
					|| dataIt->second.checkType(BValue::Type::BOOLEAN))
				{
					aInfo.isBot = dataIt->second.getInt() == 0 ? false : true;
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::IS_BOT)] = true;

				if (aInfo.isBot)
				{
					aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FOLLOWERS_COUNT)] = true;
				}
			}

			dataIt = responceParamsMap.find("total_infl_score");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER)
					|| dataIt->second.checkType(BValue::Type::FLOAT))
				{
					aInfo.influenceScore = dataIt->second.getInt();
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::TOTAL_INFLUENCE_SCORE)] = true;
			}

			dataIt = responceParamsMap.find("seasonal_infl_score");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::INTEGER)
					|| dataIt->second.checkType(BValue::Type::FLOAT))
				{
					aInfo.seasonalInfluenceScore = dataIt->second.getInt();
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::SEAS_INFLUENCE_SCORE)] = true;
			}

			dataIt = responceParamsMap.find("leader_title");
			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::MAP))
				{
					const auto& titleMap = dataIt->second.getValueMap();

					auto titleIt = titleMap.find("t");
					if (titleIt != titleMap.end())
					{
						aInfo.leaderboardTitleId = titleIt->second.getString();
					}
					else
					{
						titleIt = titleMap.find("y");
						if (titleIt != titleMap.end())
						{
							aInfo.leaderboardYear = titleIt->second.getInt();
						}

						titleIt = titleMap.find("m");
						if (titleIt != titleMap.end())
						{
							aInfo.leaderboardMonthId = titleIt->second.getInt();
						}

						titleIt = titleMap.find("w");
						if (titleIt != titleMap.end())
						{
							aInfo.leaderboardWeek = titleIt->second.getInt();
						}

						aInfo.leaderboardTitleId.clear();
					}
				}
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::LEADER_TITLE_ID)] = true;
			}

			dataIt = responceParamsMap.find("last_looks");
			if (dataIt == responceParamsMap.end())
			{
				dataIt = responceParamsMap.find("last_submitted_looks");
			}

			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::VECTOR))
				{
					auto& valueVec = dataIt->second.getValueVector();

					aInfo.lastSubmittedLooks.resize(valueVec.size());
					int counter = 0;

					for (auto& value : valueVec)
					{
						DataTypesHelper::parsePlayerStyleInfoFromBValue(value, aInfo.lastSubmittedLooks[counter]);
						++counter;
					}
				}

				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::LAST_SUBMITTED_LOOKS)] = true;
			}

			dataIt = responceParamsMap.find("best_looks");
			if (dataIt == responceParamsMap.end())
			{
				dataIt = responceParamsMap.find("best_rated_looks");
			}

			if (dataIt != responceParamsMap.end())
			{
				if (dataIt->second.checkType(BValue::Type::VECTOR))
				{
					auto& valueVec = dataIt->second.getValueVector();

					aInfo.bestRatedLooks.resize(valueVec.size());
					int counter = 0;

					for (auto& value : valueVec)
					{
						DataTypesHelper::parsePlayerStyleInfoFromBValue(value, aInfo.bestRatedLooks[counter]);
						++counter;
					}
				}

				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::BEST_RATED_LOOKS)] = true;
			}

			dataIt = responceParamsMap.find("fb_icon_enable");
			if (dataIt != responceParamsMap.end() && dataIt->second.checkType(BValue::Type::BOOLEAN))
			{
				aInfo.isFBIcon = dataIt->second.getBool();
			}
			aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FB_ICON_ENABLE)] = true;

			dataIt = responceParamsMap.find("fb_id");
			if (dataIt != responceParamsMap.end() && dataIt->second.checkType(BValue::Type::STRING))
			{
				aInfo.fbId = dataIt->second.getString();
			}
			aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FB_ID)] = true;


			dataIt = responceParamsMap.find("is_following");
			if (dataIt != responceParamsMap.end() && dataIt->second.isBoolean())
			{
				if (dataIt->second.getBool())
				{
					aInfo.followState = eFollowState::FOLLOWED;
				}
				else
				{
					aInfo.followState = eFollowState::NOT_FOLLOWED;
				}
			}

			if (aInfo.followState != eFollowState::NONE)
			{
				aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::FOLLOW_INFO)] = true;
			}

            dataIt = responceParamsMap.find("owned_items_amount");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.ownedItemsAmount = dataIt->second.getInt();             
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::OWNED_ITEMS_AMOUNT)] = true;

            dataIt = responceParamsMap.find("avatar_profile");
            if (dataIt != responceParamsMap.end())
            {
                DataTypesHelper::parseCharStyleInfoFromNetwork(dataIt->second, aInfo.profileAvatar);
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::PROFILE_AVATAR)] = true;

            dataIt = responceParamsMap.find("brandname");
            if (dataIt != responceParamsMap.end() && dataIt->second.isString())
            {
                aInfo.brandname = dataIt->second.getString();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::BRANDNAME)] = true;

            dataIt = responceParamsMap.find("submit_event_count");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.submittedAmount = dataIt->second.getInt();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::SUBMITTED_AMOUNT)] = true;

			dataIt = responceParamsMap.find("des_t_rating");
			if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
			{
				aInfo.desTotalRating = dataIt->second.getInt();
			}
			aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_TOTAL_RATING)] = true;

            dataIt = responceParamsMap.find("des_w_rating");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.desWeeklyRating = dataIt->second.getInt();
                aInfo.desTotalRating += aInfo.desWeeklyRating;
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_WEEKLY_RATING)] = true;

            dataIt = responceParamsMap.find("items_published");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.itemsPublished = dataIt->second.getInt();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_ITEMS_PUBLISHED)] = true;

            dataIt = responceParamsMap.find("gems_earned");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.gemsEarned = dataIt->second.getInt();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_GEMS_EARNED)] = true;

            dataIt = responceParamsMap.find("items_sold");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.itemsSold = dataIt->second.getInt();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_ITEMS_SOLD)] = true;

            dataIt = responceParamsMap.find("dts_earned");
            if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
            {
                aInfo.desTopSelEarned = dataIt->second.getInt();
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_TOP_SEL_EARNED)] = true;

			dataIt = responceParamsMap.find("des_exp");
			if (dataIt != responceParamsMap.end() && dataIt->second.isInteger())
			{
				aInfo.designerExperience = dataIt->second.getInt();
				aInfo.designerLevel = DM->convertExpToLevel(aInfo.designerExperience, eLevelsType::DESIGNER_LEVEL);
			}
			aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_EXP)] = true;

            dataIt = responceParamsMap.find("custom_collections");
            if (dataIt != responceParamsMap.end() && dataIt->second.isMap())
            {
                for (const auto& mapItem : dataIt->second.getValueMap())
                {
                    if(mapItem.second.isString())
                    {
                        aInfo.designerCollections.emplace(mapItem.first, mapItem.second.getString());
                    }
                }
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_COLLECTIONS)] = true;

            dataIt = responceParamsMap.find("shared_collections");
            if (dataIt != responceParamsMap.end() && dataIt->second.isVector())
            {
                for (const auto& id : dataIt->second.getValueVector())
                {
                    if (id.isString())
                    {
                        aInfo.sharedCollections.push_back(id.getString());
                    }
                }
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_SHARED_COLLECTIONS)] = true;

            dataIt = responceParamsMap.find("des_br_icon");
            if (dataIt != responceParamsMap.end() && dataIt->second.isMap())
            {
                auto brIconMap = dataIt->second.getValueMap();
                auto endIt = brIconMap.end();
                
                dataIt = brIconMap.find("name");
                if (dataIt != endIt && dataIt->second.isString())
                {
                    aInfo.desBrandIcon.name = dataIt->second.getString();
                }

                dataIt = brIconMap.find("icn_clr_id");
                if (dataIt != endIt && dataIt->second.isInteger())
                {
                    aInfo.desBrandIcon.colorIconId = dataIt->second.getInt();
                    aInfo.desBrandIcon.iconColor = ColorPickerIconController::getColorById(aInfo.desBrandIcon.colorIconId,
                        eBrandIconColorizedPart::ICON_BADGE);
                }

                dataIt = brIconMap.find("bg_clr_id");
                if (dataIt != endIt && dataIt->second.isInteger())
                {
                    aInfo.desBrandIcon.colorBgId = dataIt->second.getInt();
                    aInfo.desBrandIcon.bgColor = ColorPickerIconController::getColorById(aInfo.desBrandIcon.colorBgId,
                        eBrandIconColorizedPart::ICON_BACK);
                }
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_BRAND_ICON)] = true;

            dataIt = responceParamsMap.find("des_bg");
            if (dataIt != responceParamsMap.end() && dataIt->second.isMap())
            {
                auto desBgMap = dataIt->second.getValueMap();
                auto endIt = desBgMap.end();

                dataIt = desBgMap.find("name");
                if (dataIt != endIt && dataIt->second.isString())
                {
                    aInfo.desViewBg.name = dataIt->second.getString();
                }

                dataIt = desBgMap.find("path");
                if (dataIt != endIt && dataIt->second.isString())
                {
                    aInfo.desViewBg.path = dataIt->second.getString();
                }
            }
            aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::DES_VIEW_BG)] = true;

			dataIt = responceParamsMap.find("face_custom_bg_id");
			if (dataIt != responceParamsMap.end() && dataIt->second.isString())
			{
				aInfo.profileCustomBg = dataIt->second.getString();
			}
			aInfo.loadedInfoVec[static_cast<int>(ePlayerInfoRequirement::PROFILE_CUSTOM_BG)] = true;

			//---------------------- for live ops ----------------------//
			dataIt = responceParamsMap.find("rd_info");
			if (dataIt != responceParamsMap.end())
			{
				auto& rdInfoMap = dataIt->second.getValueMap();
				auto rdInfoIt = rdInfoMap.find("rd_points");
				if (rdInfoIt != rdInfoMap.end())
				{
					aInfo.rdPoints = rdInfoIt->second.getInt();
				}

				rdInfoIt = rdInfoMap.find("duel_count");
				if (rdInfoIt != rdInfoMap.end())
				{
					aInfo.passedDuelsCount = rdInfoIt->second.getInt();
				}

				rdInfoIt = rdInfoMap.find("win_count");
				if (rdInfoIt != rdInfoMap.end())
				{
					aInfo.winDuelsCount = rdInfoIt->second.getInt();
				}
			}

			dataIt = responceParamsMap.find("ms_info");
			if (dataIt != responceParamsMap.end())
			{
				auto& msInfoMap = dataIt->second.getValueMap();
				auto msInfoIt = msInfoMap.find("stars");
				if (msInfoIt != msInfoMap.end())
				{
					aInfo.msTotalStars = msInfoIt->second.getFloat();
				}
			}

			dataIt = responceParamsMap.find("mt_info");
			if (dataIt != responceParamsMap.end())
			{
				auto& msInfoMap = dataIt->second.getValueMap();

				auto msInfoIt = msInfoMap.find("token_c");
				if (msInfoIt != msInfoMap.end())
				{
					aInfo.mtTotalTokens = msInfoIt->second.getFloat();
				}
			}
		}
	}
}


void DataTypesHelper::parsePlayerStyleInfoFromBValue(const BValue & aRawValue, sPlayerStyleInfo & aInfo)
{
	if (aRawValue.checkType(BValue::Type::MAP))
	{
		const DataStorageComponentConstRef rawMap = aRawValue.getValueMap();

		DataTypesHelper::parseCharStyleInfoFromNetwork(rawMap.getValue("lookInfo"), aInfo.playerStyle);
		 
		if (rawMap.hasValue("uid"))
		{
			aInfo.uniqueID = rawMap.getString("uid");
		}
		else
		{
			aInfo.uniqueID = rawMap.getString("uniqueID");
		}

		if (rawMap.hasValue("eid"))
		{
			aInfo.eventID = rawMap.getString("eid");
		}
		else 
		{
			aInfo.eventID = rawMap.getString("eventID");
		}

		if (rawMap.hasValue("title"))
		{
			aInfo.titleID = rawMap.getString("title");
		}
		else
		{
			aInfo.titleID = rawMap.getString("titleID");
		}

		for (auto& singleReward : rawMap.getVector("rewards"))
		{
			aInfo.rewards.push_back(DataTypesHelper::serializeBValueToEventRewardInfo(singleReward));
		}

		std::string bonusesKey = "bonuses";
		if ( !rawMap.hasValue("bonuses") )
		{
			bonusesKey = "bonusesInfo";
		}

		aInfo.lookBonuses.clear();
		for (auto& bonusRaw : rawMap.getVector( bonusesKey ) )
		{
			if (bonusRaw.checkType(BValue::Type::INTEGER))
			{
				int bonusInfoInt = bonusRaw.getInt();

				if (bonusInfoInt > static_cast<int>(eBonusType::UNDEFINED) && bonusInfoInt < static_cast<int>(eBonusType::BONUS_ENUM_END))
				{
					aInfo.lookBonuses[static_cast<eBonusType>(bonusInfoInt)] = true;
				}
			}
		}

		if (rawMap.hasValue("stars"))
		{
			const auto& starsValue = rawMap.getValue("stars");
			if (starsValue.isString() || starsValue.isFloat())
			{
				aInfo.starsCount = starsValue.getFloat();
			}
			else if(starsValue.isInteger())
			{
				aInfo.starsCount = static_cast<float>(starsValue.getInt());
			}
		}
		else
		{
			const auto& starsValue = rawMap.getValue("starsCount");
			if (starsValue.isString() || starsValue.isFloat())
			{
				aInfo.starsCount = starsValue.getFloat();
			}
			else if (starsValue.isInteger())
			{
				aInfo.starsCount = static_cast<float>(starsValue.getInt());
			}
		}

		if (rawMap.hasValue("locId"))
		{
			aInfo.locationID = rawMap.getString("locId");
		}
		else
		{
			aInfo.locationID = rawMap.getString("locationID");
		}

		if ( rawMap.hasValue( "score" ) )
		{
			aInfo.influenceScore = rawMap.getInt("score", aInfo.influenceScore);
		}
		else
		{
			aInfo.influenceScore = rawMap.getInt("scoreValue", aInfo.influenceScore);
		}

		std::string voteKey = "v_time";
		if ( !rawMap.hasValue("v_time") )
		{
			voteKey = "voteEndTime";
		}

		auto& valueVoteEndTime = rawMap.getValue( voteKey );
		if (valueVoteEndTime.isString())
		{
			aInfo.endTime = std::stol(valueVoteEndTime.getString());
		}
		else
		{
			aInfo.endTime = valueVoteEndTime.getInt();
		}

		if (rawMap.hasValue("s_time"))
		{
			aInfo.submitTime = rawMap.getInt("s_time");
		}
		else
		{
			aInfo.submitTime = rawMap.getInt("lookSubmitTime");
		}

		aInfo.likesCount = rawMap.getInt("likesCount");

		aInfo.likedBy.clear();

		for (auto& playerRaw : rawMap.getVector("likedBy"))
		{
			aInfo.likedBy.push_back(playerRaw.getString());
		}

		if (rawMap.hasValue("pid"))
		{
			aInfo.ownerPlayerID = rawMap.getString("pid");
		}
		else
		{
			aInfo.ownerPlayerID = rawMap.getString("playerID");
		}
		
		if ( rawMap.hasValue( "is_x2" ) )
		{
			aInfo.isDoubleInfluence = rawMap.getBool("is_x2");
		}
		else
		{
			aInfo.isDoubleInfluence = rawMap.getBool("isDoubleInfluence");
		}
	}
}

bool DataTypesHelper::parseCharStyleInfoFromNetwork( const BValue& aCharStyleRaw, sCharStyleInfo& aInfo )
{
	bool isConvertedFromOldSave = false;
	if (aCharStyleRaw.checkType(BValue::Type::MAP))
	{
		const BValueMap& styleMapRaw = aCharStyleRaw.getValueMap();

		auto mapItr = styleMapRaw.find("skin");
		if (mapItr != styleMapRaw.end() && !mapItr->second.getString().empty() )
		{
			BValue skinStr;
			skinStr.initWithFormat("skin_%s", mapItr->second.getString().c_str() );
			aInfo.customizeInfo.skin_id = skinStr.getString();
		}
		else
		{
			// old( before ver. 2.0.0 )
			mapItr = styleMapRaw.find("skin_id");
			if (mapItr != styleMapRaw.end())
			{
				aInfo.customizeInfo.skin_id = mapItr->second.getString();
			}
		}

		mapItr = styleMapRaw.find("looks");
		aInfo.looks.clear();

		if (mapItr != styleMapRaw.end())
		{
			std::map< eLookType, std::string > looks;
			if ( mapItr->second.checkType( BValue::Type::VECTOR ) )
			{
				// old ( before ver. 2.0.0 )
				const BValueVector& looksVec = mapItr->second.getValueVector();
				for (auto& lookRawString : looksVec)
				{
					auto stringsVec = BCHelper::getSplitStringsVecWithSeparator(lookRawString.getString(), "|", false);

					if (stringsVec.size() == 2)
					{
						eLookType type = getLookTypeFromStr(stringsVec[0]);
						if (type == eLookType::UNDEFINED)
						{
                            auto typeValue = stringsVec[0];
                            if (!typeValue.empty() && std::find_if(typeValue.begin(), typeValue.end(), [](unsigned char c) { return !isdigit(c); }) == typeValue.end())
                            {
                                type = static_cast<eLookType>(std::stoi(stringsVec[0].c_str()));
                            }
						}
							
						if ( type != eLookType::UNDEFINED )
						{
							looks[type] = stringsVec[1];
						}
					}
				}
			}

			for (auto& lookIt : looks)
			{
				auto lookID = DM->getLookIDByOldID(lookIt.second);
				aInfo.looks[lookIt.first] = lookID;
				isConvertedFromOldSave |= lookIt.second != lookID;
			}
		}

		// faceParts start //
		std::map< eCharFacePart, std::string> faceParts;
		aInfo.customizeInfo.faceParts.clear();

		mapItr = styleMapRaw.find("face");
		if (mapItr != styleMapRaw.end() && mapItr->second.isString())
		{
			std::vector<std::string> stringValues = BCHelper::getSplitStringsVecWithSeparator(mapItr->second.getString(), "|", false);
			int index = 1;
			for (auto& value : stringValues)
			{
				eCharFacePart part = static_cast<eCharFacePart>(index);
				if (part != eCharFacePart::UNDEFINED && !value.empty())
				{
					faceParts[part] = value;
				}

				++index;
			}
		}
		else
		{
			// old ( before ver. 2.0.0 )
			mapItr = styleMapRaw.find("faceParts");
			if (mapItr != styleMapRaw.end() && mapItr->second.isVector())
			{
				const BValueVector& facePartVecRaw = mapItr->second.getValueVector();

				for (auto& facePartInfoRaw : facePartVecRaw)
				{
					std::vector<std::string> stringValues = BCHelper::getSplitStringsVecWithSeparator(facePartInfoRaw.getString(), "|", false);
					if (stringValues.size() == 2)
					{
						eCharFacePart part = getCharFacePartFromStr(stringValues[0]);

						if (part != eCharFacePart::UNDEFINED)
						{
							faceParts[part] = stringValues[1];
						}
					}
				}
			}
		}

		for (auto& facePartIt : faceParts)
		{
			auto lookID = DM->getLookIDByOldID(facePartIt.second);

			std::string faceLookGroup = DataTypesHelper::getStrFromCharFacePart(facePartIt.first);
			if (DM->isLooksGroupHasLook(faceLookGroup, lookID))
			{
				aInfo.customizeInfo.faceParts[facePartIt.first] = lookID;
			}
			else {
				isConvertedFromOldSave = true;
			}

			isConvertedFromOldSave |= facePartIt.second != lookID;
		}
		// faceParts end //

				// colorized start //
		std::map< eCharColorizedPart, std::string> colorizedParts;
		aInfo.customizeInfo.colorParts.clear();

		mapItr = styleMapRaw.find("colors");
		if (mapItr != styleMapRaw.end() && mapItr->second.isString())
		{
			std::vector<std::string> stringValues = BCHelper::getSplitStringsVecWithSeparator(mapItr->second.getString(), "|", false);
			int index = 1;
			for (auto& value : stringValues)
			{
				eCharColorizedPart part = static_cast<eCharColorizedPart>(index);
				if (part != eCharColorizedPart::UNDEFINED)
				{
					colorizedParts[part] = value;
				}

				++index;
			}
		}
		else
		{
			// old ( before ver. 2.0.0 )
			mapItr = styleMapRaw.find("colorizedParts");
			if (mapItr != styleMapRaw.end() && mapItr->second.isVector())
			{
				const BValueVector& facePartVecRaw = mapItr->second.getValueVector();
				for (auto& facePartInfoRaw : facePartVecRaw)
				{
					std::vector<std::string> stringValues = BCHelper::getSplitStringsVecWithSeparator(facePartInfoRaw.getString(), "|", false);

					if (stringValues.size() == 2)
					{
						eCharColorizedPart part = getCharColorizedPartFromStr(stringValues[0]);

						if (part != eCharColorizedPart::UNDEFINED)
						{
							colorizedParts[part] = stringValues[1];
						}
					}
				}
			}
		}

		for (auto& partIt : colorizedParts)
		{
			Color4F color = DM->getCharPartColorByColorIndex(partIt.first, partIt.second);
			if (color != Color4F(0.0f, 0.0f, 0.0f, 0.0f))
			{
				aInfo.customizeInfo.colorParts[partIt.first] = color;
			}
			else
			{
				BValue val(partIt.second);
				aInfo.customizeInfo.colorParts[partIt.first] = val.getColor4F();
				isConvertedFromOldSave = true;
			}
		}
		// colorized end //

		mapItr = styleMapRaw.find("is_hair_ends_enabled");
		if (mapItr != styleMapRaw.end())
		{
			aInfo.customizeInfo.isHairEndsEnabled = mapItr->second.getBool();
		}
	}

	return isConvertedFromOldSave;
}

void DataTypesHelper::parseCharStyleInfoFromConfig( const BValue& aRawValue, sCharStyleInfo& aInfo )
{
	if (aRawValue.isMap())
	{
		parseCharStyleInfoFromNetwork(aRawValue, aInfo);

		auto& charStyleValueMap = aRawValue.getValueMap();

		auto customizeInfoValueItr = charStyleValueMap.find("customize_info");
		if (customizeInfoValueItr != charStyleValueMap.end())
		{
			auto& customizeInfoMap = customizeInfoValueItr->second.getValueMap();

			auto customizeInfoMapItr = customizeInfoMap.find("color_parts");

			if (customizeInfoMapItr != customizeInfoMap.end())
			{
				for (auto& colorValuePair : customizeInfoMapItr->second.getValueMap())
				{
					auto& value = colorValuePair.second;
					eCharColorizedPart colorizedPart = DataTypesHelper::getCharColorizedPartFromStr(colorValuePair.first);

					const std::string& colorIndex = value.getString();
					Color4F color = DM->getCharPartColorByColorIndex(colorizedPart, colorIndex);
					if (color != Color4F(0.0f, 0.0f, 0.0f, 0.0f))
					{
						aInfo.customizeInfo.colorParts[colorizedPart] = color;
					}
					else
					{
						aInfo.customizeInfo.colorParts[colorizedPart] = value.getColor4F();
					}
				}
			}

			customizeInfoMapItr = customizeInfoMap.find("face_parts");

			if (customizeInfoMapItr != customizeInfoMap.end())
			{
				for (auto& faceValuePair : customizeInfoMapItr->second.getValueMap())
				{
					auto id = faceValuePair.second.getString();

					auto lookId = DM->getLookIDByOldID(id);
					aInfo.customizeInfo.faceParts[DataTypesHelper::getCharFacePartFromStr(faceValuePair.first)] = lookId;
				}
			}

			customizeInfoMapItr = customizeInfoMap.find("skin_id");
			if (customizeInfoMapItr != customizeInfoMap.end())
			{
				aInfo.customizeInfo.skin_id = customizeInfoMapItr->second.getString();
			}

			customizeInfoMapItr = customizeInfoMap.find("is_hair_ends_enabled");

			if (customizeInfoMapItr != customizeInfoMap.end())
			{
				aInfo.customizeInfo.isHairEndsEnabled = customizeInfoMapItr->second.getBool();
			}
		}

		if( aInfo.looks.empty() )
		{
			customizeInfoValueItr = charStyleValueMap.find("looks");
			if (customizeInfoValueItr != charStyleValueMap.end())
			{
				for (auto& lookValuePair : customizeInfoValueItr->second.getValueMap())
				{
					auto id = lookValuePair.second.getString();

					auto lookId = DM->getLookIDByOldID(id);
					aInfo.looks[DataTypesHelper::getLookTypeFromStr(lookValuePair.first)] = lookId;
				}
			}
		}
	}
}

void DataTypesHelper::parseEventRewardInfo(const BValue & aEvRewardRaw, sEventRewardInfo & aInfo)
{
	if (aEvRewardRaw.isMap())
	{
		auto& evRewardsRawMap = aEvRewardRaw.getValueMap();

		auto evRewardMapItr = evRewardsRawMap.find("required_stars");
		if (evRewardMapItr != evRewardsRawMap.end())
		{
			aInfo.requiredStarsCount = std::atoi(evRewardMapItr->second.getString().c_str());
		}

		evRewardMapItr = evRewardsRawMap.find("reward_amount");
		if (evRewardMapItr != evRewardsRawMap.end())
		{
			aInfo.rewardsAmount = std::atoi(evRewardMapItr->second.getString().c_str());
		}

		evRewardMapItr = evRewardsRawMap.find("reward_look_id");
		if (evRewardMapItr != evRewardsRawMap.end())
		{
			aInfo.rewardLookId = evRewardMapItr->second.getString();
		}

		evRewardMapItr = evRewardsRawMap.find("reward_type");
		if (evRewardMapItr != evRewardsRawMap.end())
		{
			aInfo.rewardType = DataTypesHelper::getEventRewardTypeFromString(evRewardMapItr->second.getString());
		}
	}

}

void DataTypesHelper::parseEventRewardInfo(const rapidjson::Value & aEvRewardRaw, sEventRewardInfo & aInfo)
{
	if (aEvRewardRaw.IsObject())
	{
		if (aEvRewardRaw.HasMember("required_stars"))
		{
			aInfo.requiredStarsCount = std::atoi(aEvRewardRaw["required_stars"].GetString());
		}

		if (aEvRewardRaw.HasMember("reward_amount"))
		{
			if (aEvRewardRaw["reward_amount"].IsString())
			{
				aInfo.rewardsAmount = std::atoi(aEvRewardRaw["reward_amount"].GetString());
			}
			else if (aEvRewardRaw["reward_amount"].IsNumber())
			{
				aInfo.rewardsAmount = aEvRewardRaw["reward_amount"].GetInt();
			}
		}

		if (aEvRewardRaw.HasMember("reward_look_id") && aEvRewardRaw["reward_look_id"].IsString())
		{
			aInfo.rewardLookId = aEvRewardRaw["reward_look_id"].GetString();
		}

		if (aEvRewardRaw.HasMember("reward_type") && aEvRewardRaw["reward_type"].IsString())
		{
			aInfo.rewardType = DataTypesHelper::getEventRewardTypeFromString(aEvRewardRaw["reward_type"].GetString());
		}
	}

}

std::vector< std::string > DataTypesHelper::getArchetypeVectorFromArchetype( const std::string& aArchetype )
{
	std::vector< std::string > result;

	auto splitVec = BCHelper::getSplitStringsVecWithSeparator( aArchetype );
	if ( splitVec.empty() )
	{
		result.push_back( aArchetype );
	}
	else
	{
		for ( const auto& element : splitVec )
		{
			if ( !element.empty() )
			{
				result.push_back( element );
			}
		}
	}

	return result;
}

/* --------------------------------------- CDN REFRACTORING ---------------------------------------*/
bool DataTypesHelper::isItemArchetypeCorrect(const std::string& aCondition, const sArchetype* aArhetypeInfo)
{
	bool result = false;

	if (aArhetypeInfo)
	{
		std::vector< std::string > conditionVec = BCHelper::getSplitStringsVecWithSeparator(aCondition);
		if (!conditionVec.empty())
		{
			sArchetype archetypeTemp;
			archetypeTemp.archetype = conditionVec[0];
			for (size_t i = 1; i < conditionVec.size(); i++)
			{
				archetypeTemp.tags.push_back(conditionVec[i]);
			}

			result = aArhetypeInfo->includes(archetypeTemp);
		}
		else if (!aCondition.empty())
		{
			result = aArhetypeInfo->archetype == aCondition;
		}
	}

	return result;
}

/* --------------------------------------- CDN REFRACTORING ---------------------------------------*/

BValueMap DataTypesHelper::getBValueMapFromStringSaveAchievement( const std::string& aSave )
{
	BValueMap result;

	auto vector = BCHelper::getSplitStringsVecWithSeparator( aSave, "|", true );
	if ( vector.size() == mAchieveMaxFields )
	{
		for ( unsigned int i = 0u; i < vector.size(); i++ )
		{
			std::string info = vector[ i ];
			std::string key;

			if ( info != "-" )
			{
				eAchieveSaveKey saveKey = static_cast< eAchieveSaveKey >( i );
				key = getStringByAchieveSaveKey( saveKey );

				if ( saveKey != eAchieveSaveKey::SPECIAL_CHECK_MODULES )
				{
					if ( saveKey == eAchieveSaveKey::UNIQUE_ID )
					{
						result[ key ] = getAchievementIdFromEnum( static_cast< eAchievementId >( std::stoi( info ) ) );
					}
					else
					{
						result[ key ] = info;
					}
				}
				else
				{
					auto specialInfoVec = BCHelper::getSplitStringsVecWithSeparator( info, "@", false );
					if ( specialInfoVec.size() == 2 )
					{
						BValueMap specialInfo;
						
						BValue specialFirst = specialInfoVec[ 0 ];
						BValue specialSec = specialInfoVec[ 1 ];

						auto secVec = BCHelper::getSplitStringsVecWithSeparator( specialSec.getString(), "+", false );
                        BValueVector secondVector;
						if ( secVec.size() > 1 )
						{
							for ( const auto& element : secVec )
							{
								secondVector.push_back( element );
							}
							specialInfo[ specialInfoVec[ 0 ] ] = secondVector;
						}
						else
						{
                            secondVector.push_back( specialInfoVec[ 1 ] );
						}
                        specialInfo[specialInfoVec[0]] = secondVector;
						result[ key ] = specialInfo;
					}
				}
			}
		}
	}

	return result;
}

std::string DataTypesHelper::getStringFromBValueAchievement( const BValueMap& aMap )
{
	std::string result;

	for ( int i = 0; i < mAchieveMaxFields; i++ )
	{
		std::string valueToSave;
		std::string key;

		eAchieveSaveKey saveKey = static_cast< eAchieveSaveKey >( i );
		key = getStringByAchieveSaveKey( saveKey );

		auto findIt = aMap.find( key );
		if ( findIt != aMap.end() )
		{
			if ( saveKey == eAchieveSaveKey::SPECIAL_CHECK_MODULES && findIt->second.isMap() )
			{
				BValueMap infoMap = findIt->second.getValueMap();
				if ( infoMap.size() > 0 )
				{
					std::pair< std::string, BValue > pair = *infoMap.begin();
					result.append( pair.first );
					result.append( "@" );
					if ( pair.second.checkType( BValue::Type::STRING ) )
					{
						result.append( pair.second.getString() );
					}
					else if ( pair.second.checkType( BValue::Type::VECTOR ) )
					{
						auto vecInfo = pair.second.getValueVector();
						if ( vecInfo.size() > 0 )
						{
							for ( const auto& element : vecInfo )
							{
								result.append( element.getString() );
								result.append( "+" );
							}

							result = result.substr( 0, result.size() - 1 );
						}
					}
				}
				else
				{
					result.append( "-" );
				}
			}
			else if ( saveKey == eAchieveSaveKey::UNIQUE_ID )
			{
				result.append( std::to_string( static_cast<int>( getAchievementEnumFromString( findIt->second.getString() ) ) ) );
			}
			else
			{
				result.append( findIt->second.getString() );
			}
		}
		else
		{
			result.append( "-" );
		}

		result.append( "|" );
	}

	return result;
}

eAchievementId DataTypesHelper::getAchievementEnumFromString( const std::string& aAchievementId )
{
	eAchievementId result = eAchievementId::UNDEFINED;

	if ( aAchievementId == "WISH_ITEM" )
	{
		result = eAchievementId::WISH_ITEM;
	}
	else if ( aAchievementId == "FOLLOW_PLAYER" )
	{
		result = eAchievementId::FOLLOW_PLAYER;
	}
	else if ( aAchievementId == "LIKE_LOOKS" )
	{
		result = eAchievementId::LIKE_LOOKS;
	}
	else if ( aAchievementId == "OBTAIN_FULL_COLLECTION" )
	{
		result = eAchievementId::OBTAIN_FULL_COLLECTION;
	}
	else if ( aAchievementId == "VOTE_WITH_MAX_TICKETS" )
	{
		result = eAchievementId::VOTE_WITH_MAX_TICKETS;
	}
	else if ( aAchievementId == "OWN_ITEMS" )
	{
		result = eAchievementId::OWN_ITEMS;
	}
	else if ( aAchievementId == "OWN_SKIRTS" )
	{
		result = eAchievementId::OWN_SKIRTS;
	}
	else if ( aAchievementId == "OWN_SNEAKERS" )
	{
		result = eAchievementId::OWN_SNEAKERS;
	}
	else if ( aAchievementId == "OWN_LEATHER" )
	{
		result = eAchievementId::OWN_LEATHER;
	}
	else if ( aAchievementId == "BECOME_TRENDSETTER" )
	{
		result = eAchievementId::BECOME_TRENDSETTER;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_1" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_1;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_2" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_2;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_3" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_3;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_4" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_4;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_5" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_5;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_6" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_6;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_7" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_7;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_8" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_8;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_9" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_9;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_LOCATION_10" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_LOCATION_10;
	}
	else if ( aAchievementId == "COLLECT_STARS" )
	{
		result = eAchievementId::COLLECT_STARS;
	}
	else if ( aAchievementId == "COMPLETE_WEEKLY_CHALLENGES" )
	{
		result = eAchievementId::COMPLETE_WEEKLY_CHALLENGES;
	}
	else if ( aAchievementId == "GET_TOTAL_INFLUENCE" )
	{
		result = eAchievementId::GET_TOTAL_INFLUENCE;
	}
	else if ( aAchievementId == "SUBMIT_LOOKS_IN_SEASONS" )
	{
		result = eAchievementId::SUBMIT_LOOKS_IN_SEASONS;
	}
	else if ( aAchievementId == "PLAY_DAYS_ROW" )
	{
		result = eAchievementId::PLAY_DAYS_ROW;
	}
	else if (aAchievementId == "COMPLETE_EVENT_WITH_5_STARS")
	{
		result = eAchievementId::COMPLETE_EVENT_WITH_5_STARS;
	}
	else if (aAchievementId == "EARN_TOTAL_GEMS")
	{
		result = eAchievementId::EARN_TOTAL_GEMS;
	}
	else if (aAchievementId == "OBTAIN_LIMITED_ITEMS")
	{
		result = eAchievementId::OBTAIN_LIMITED_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOK_WITH_15_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOK_WITH_15_ITEMS;
	}
	else if (aAchievementId == "USE_TOTAL_CONSUMABLES")
	{
		result = eAchievementId::USE_TOTAL_CONSUMABLES;
	}
	else if (aAchievementId == "BUY_LOOK_OF_THE_DAY")
	{
		result = eAchievementId::BUY_LOOK_OF_THE_DAY;
	}
	else if (aAchievementId == "SAVE_FACE_PRESETS")
	{
		result = eAchievementId::SAVE_FACE_PRESETS;
	}
	else if (aAchievementId == "OBTAIN_DAILY_DEALS")
	{
		result = eAchievementId::OBTAIN_DAILY_DEALS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONE_STYLE_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONE_STYLE_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ITEMS_FROM_ONE_COLLECTION")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ITEMS_FROM_ONE_COLLECTION;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONE_COLOR_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONE_COLOR_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONE_FABRIC_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONE_FABRIC_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONE_PATTERN_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONE_PATTERN_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_SUMMER_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_SUMMER_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_FALL_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_FALL_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_WINTER_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_WINTER_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_SPRING_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_SPRING_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONLY_UNWORN_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONLY_UNWORN_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONLY_TRENDING_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONLY_TRENDING_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONLY_LIMITED_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONLY_LIMITED_ITEMS;
	}
	else if (aAchievementId == "UPDATE_PROFILE_AVATAR_MODEL")
	{
		result = eAchievementId::UPDATE_PROFILE_AVATAR_MODEL;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ITEMS_FROM_DIFFERENT_COLLECTIONS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ITEMS_FROM_DIFFERENT_COLLECTIONS;
	}
	else if (aAchievementId == "LIKE_A_LOOK_IN_EVERY_LOCATION")
	{
		result = eAchievementId::LIKE_A_LOOK_IN_EVERY_LOCATION;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_DIFFERENT_HAIR_COLORS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_DIFFERENT_HAIR_COLORS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_DIFFERENT_EYE_COLORS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_DIFFERENT_EYE_COLORS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WEARING_A_COMPLETE_HOLIDAY_OUTFIT")
	{
		result = eAchievementId::SUBMIT_LOOKS_WEARING_A_COMPLETE_HOLIDAY_OUTFIT;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_ONLY_SUCH_ITEMS")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_ONLY_SUCH_ITEMS;
	}
	else if (aAchievementId == "SUBMIT_LOOKS_WITH_REQ_IN_LOCATION")
	{
		result = eAchievementId::SUBMIT_LOOKS_WITH_REQ_IN_LOCATION;
	}
	else if (aAchievementId == "OWN_BOOTS")
	{
		result = eAchievementId::OWN_BOOTS;
	}
	else if (aAchievementId == "OWN_SWEATERS")
	{
		result = eAchievementId::OWN_SWEATERS;
	}
	else if (aAchievementId == "OWN_WOOL")
	{
		result = eAchievementId::OWN_WOOL;
	}

	return result;
}

std::string DataTypesHelper::getAchievementIdFromEnum( eAchievementId aId )
{
	std::string result;

	switch ( aId )
	{
		case eAchievementId::WISH_ITEM:
			result = "WISH_ITEM";
			break;
		case eAchievementId::FOLLOW_PLAYER:
			result = "FOLLOW_PLAYER";
			break;
		case eAchievementId::LIKE_LOOKS:
			result = "LIKE_LOOKS";
			break;
		case eAchievementId::OBTAIN_FULL_COLLECTION:
			result = "OBTAIN_FULL_COLLECTION";
			break;
		case eAchievementId::VOTE_WITH_MAX_TICKETS:
			result = "VOTE_WITH_MAX_TICKETS";
			break;
		case eAchievementId::OWN_ITEMS:
			result = "OWN_ITEMS";
			break;
		case eAchievementId::OWN_SKIRTS:
			result = "OWN_SKIRTS";
			break;
		case eAchievementId::OWN_SNEAKERS:
			result = "OWN_SNEAKERS";
			break;
		case eAchievementId::OWN_LEATHER:
			result = "OWN_LEATHER";
			break;
		case eAchievementId::BECOME_TRENDSETTER:
			result = "BECOME_TRENDSETTER";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_1:
			result = "SUBMIT_LOOKS_IN_LOCATION_1";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_2:
			result = "SUBMIT_LOOKS_IN_LOCATION_2";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_3:
			result = "SUBMIT_LOOKS_IN_LOCATION_3";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_4:
			result = "SUBMIT_LOOKS_IN_LOCATION_4";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_5:
			result = "SUBMIT_LOOKS_IN_LOCATION_5";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_6:
			result = "SUBMIT_LOOKS_IN_LOCATION_6";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_7:
			result = "SUBMIT_LOOKS_IN_LOCATION_7";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_8:
			result = "SUBMIT_LOOKS_IN_LOCATION_8";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_9:
			result = "SUBMIT_LOOKS_IN_LOCATION_9";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_LOCATION_10:
			result = "SUBMIT_LOOKS_IN_LOCATION_10";
			break;
		case eAchievementId::COLLECT_STARS:
			result = "COLLECT_STARS";
			break;
		case eAchievementId::COMPLETE_WEEKLY_CHALLENGES:
			result = "COMPLETE_WEEKLY_CHALLENGES";
			break;
		case eAchievementId::GET_TOTAL_INFLUENCE:
			result = "GET_TOTAL_INFLUENCE";
			break;
		case eAchievementId::SUBMIT_LOOKS_IN_SEASONS:
			result = "SUBMIT_LOOKS_IN_SEASONS";
			break;
		case eAchievementId::PLAY_DAYS_ROW:
			result = "PLAY_DAYS_ROW";
			break;
		case eAchievementId::COMPLETE_EVENT_WITH_5_STARS:
			result = "COMPLETE_EVENT_WITH_5_STARS";
			break;
		case eAchievementId::EARN_TOTAL_GEMS:
			result = "EARN_TOTAL_GEMS";
			break;
		case eAchievementId::OBTAIN_LIMITED_ITEMS:
			result = "OBTAIN_LIMITED_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOK_WITH_15_ITEMS:
			result = "SUBMIT_LOOK_WITH_15_ITEMS";
			break;
		case eAchievementId::USE_TOTAL_CONSUMABLES:
			result = "USE_TOTAL_CONSUMABLES";
			break;
		case eAchievementId::BUY_LOOK_OF_THE_DAY:
			result = "BUY_LOOK_OF_THE_DAY";
			break;
		case eAchievementId::SAVE_FACE_PRESETS:
			result = "SAVE_FACE_PRESETS";
			break;
		case eAchievementId::OBTAIN_DAILY_DEALS:
			result = "OBTAIN_DAILY_DEALS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONE_STYLE_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONE_STYLE_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ITEMS_FROM_ONE_COLLECTION:
			result = "SUBMIT_LOOKS_WITH_ITEMS_FROM_ONE_COLLECTION";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONE_COLOR_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONE_COLOR_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONE_FABRIC_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONE_FABRIC_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONE_PATTERN_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONE_PATTERN_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_SUMMER_ITEMS:
			result = "SUBMIT_LOOKS_WITH_SUMMER_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_FALL_ITEMS:
			result = "SUBMIT_LOOKS_WITH_FALL_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_WINTER_ITEMS:
			result = "SUBMIT_LOOKS_WITH_WINTER_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_SPRING_ITEMS:
			result = "SUBMIT_LOOKS_WITH_SPRING_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONLY_UNWORN_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONLY_UNWORN_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONLY_TRENDING_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONLY_TRENDING_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONLY_LIMITED_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONLY_LIMITED_ITEMS";
			break;
		case eAchievementId::UPDATE_PROFILE_AVATAR_MODEL:
			result = "UPDATE_PROFILE_AVATAR_MODEL";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ITEMS_FROM_DIFFERENT_COLLECTIONS:
			result = "SUBMIT_LOOKS_WITH_ITEMS_FROM_DIFFERENT_COLLECTIONS";
			break;
		case eAchievementId::LIKE_A_LOOK_IN_EVERY_LOCATION:
			result = "LIKE_A_LOOK_IN_EVERY_LOCATION";
			break; 
		case eAchievementId::SUBMIT_LOOKS_WITH_DIFFERENT_HAIR_COLORS:
			result = "SUBMIT_LOOKS_WITH_DIFFERENT_HAIR_COLORS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_DIFFERENT_EYE_COLORS:
			result = "SUBMIT_LOOKS_WITH_DIFFERENT_EYE_COLORS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WEARING_A_COMPLETE_HOLIDAY_OUTFIT:
			result = "SUBMIT_LOOKS_WEARING_A_COMPLETE_HOLIDAY_OUTFIT";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_ONLY_SUCH_ITEMS:
			result = "SUBMIT_LOOKS_WITH_ONLY_SUCH_ITEMS";
			break;
		case eAchievementId::SUBMIT_LOOKS_WITH_REQ_IN_LOCATION:
			result = "SUBMIT_LOOKS_WITH_REQ_IN_LOCATION";
			break;
		case eAchievementId::OWN_BOOTS:
			result = "OWN_BOOTS";
			break;
		case eAchievementId::OWN_SWEATERS:
			result = "OWN_SWEATERS";
			break;
		case eAchievementId::OWN_WOOL:
			result = "OWN_WOOL";
			break;
	}

	return result;
}

DataTypesHelper::eAchieveSaveKey DataTypesHelper::getAchieveSaveKeyByString( const std::string& aKey )
{
	eAchieveSaveKey result;

	if ( aKey == "unique_id" )
	{
		result = eAchieveSaveKey::UNIQUE_ID;
	}
	else if ( aKey == "quest_state" )
	{
		result = eAchieveSaveKey::QUEST_STATE;
	}
	else if ( aKey == "achievement_iteration" )
	{
		result = eAchieveSaveKey::ACHIEVEMENT_ITERATION;
	}
	else if ( aKey == "required_days_count" )
	{
		result = eAchieveSaveKey::REQUIRED_DAYS_COUNT;
	}
	else if ( aKey == "current_days_count" )
	{
		result = eAchieveSaveKey::CURRENT_DAYS_COUNT;
	}
	else if ( aKey == "new_day_start_time" )
	{
		result = eAchieveSaveKey::NEW_DAY_START_TIME;
	}
	else if ( aKey == "current_progress_count" )
	{
		result = eAchieveSaveKey::CURRENT_PROGRESS_COUNT;
	}
	else if ( aKey == "required_progress_count" )
	{
		result = eAchieveSaveKey::REQUIRED_PROGRESS_COUNT;
	}
	else if ( aKey == "special_check_modules" )
	{
		result = eAchieveSaveKey::SPECIAL_CHECK_MODULES;
	}

	return result;
}

std::string DataTypesHelper::getStringByAchieveSaveKey( DataTypesHelper::eAchieveSaveKey aKey )
{
	std::string result;

	if ( aKey == eAchieveSaveKey::UNIQUE_ID )
	{
		result = "unique_id";
	}
	else if ( aKey == eAchieveSaveKey::QUEST_STATE )
	{
		result = "quest_state";
	}
	else if ( aKey == eAchieveSaveKey::ACHIEVEMENT_ITERATION )
	{
		result = "achievement_iteration";
	}
	else if ( aKey == eAchieveSaveKey::REQUIRED_DAYS_COUNT )
	{
		result = "required_days_count";
	}
	else if ( aKey == eAchieveSaveKey::CURRENT_DAYS_COUNT )
	{
		result = "current_days_count";
	}
	else if ( aKey == eAchieveSaveKey::NEW_DAY_START_TIME )
	{
		result = "new_day_start_time";
	}
	else if ( aKey == eAchieveSaveKey::CURRENT_PROGRESS_COUNT )
	{
		result = "current_progress_count";
	}
	else if ( aKey == eAchieveSaveKey::REQUIRED_PROGRESS_COUNT )
	{
		result = "required_progress_count";
	}
	else if ( aKey == eAchieveSaveKey::SPECIAL_CHECK_MODULES )
	{
		result = "special_check_modules";
	}

	return result;
}

BValueMap DataTypesHelper::getBValueMapFromStringSaveQuest( const std::string& aSave )
{
	BValueMap result;

	auto vector = BCHelper::getSplitStringsVecWithSeparator( aSave, "|", true );
	if ( vector.size() == mQuestMaxFields )
	{
		for ( unsigned i = 0u; i < vector.size(); i++ )
		{
			std::string info = vector[ i ];
			std::string key;

			if ( info != "-" )
			{
				eQuestSaveKey saveKey = static_cast< eQuestSaveKey >( i );
				key = getStringFromQuestSaveKey( saveKey );

				if ( saveKey == eQuestSaveKey::UNIQUE_ID )
				{
					result[ key ] = getQuestIdFromEnum( static_cast< eQuestId >( std::stoi( info ) ) );
				}
				else
				{
					result[ key ] = info;
				}
			}
		}
	}

	return result;
}

std::string DataTypesHelper::getStringFromBValueQuest( const BValueMap& aMap )
{
	std::string result;

	for ( int i = 0; i < mQuestMaxFields; i++ )
	{
		std::string valueToSave;
		std::string key;

		eQuestSaveKey saveKey = static_cast< eQuestSaveKey >( i );
		key = getStringFromQuestSaveKey( saveKey );

		auto findIt = aMap.find( key );
		if ( findIt != aMap.end() )
		{
			result.append( findIt->second.getString() );
		}
		else
		{
			result.append( "-" );
		}

		result.append( "|" );
	}

	return result;
}

eQuestId DataTypesHelper::getQuestEnumFromString( const std::string& aQuestId )
{
	eQuestId result = eQuestId::UNDEFINED;

	if ( aQuestId == "VOTE_ON_LOOKS_1" )
	{
		result = eQuestId::VOTE_ON_LOOKS_1;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_COTTON_2" )
	{
		result = eQuestId::SUBMIT_WITHOUT_COTTON_2;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_3" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_3;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_4" )
	{
		result = eQuestId::OBTAIN_ITEMS_4;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_5" )
	{
		result = eQuestId::SUBMIT_LOOKS_5;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_6" )
	{
		result = eQuestId::VOTE_ON_LOOKS_6;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_COTTON_7" )
	{
		result = eQuestId::SUBMIT_WITHOUT_COTTON_7;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_8" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_8;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_9" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_9;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_10" )
	{
		result = eQuestId::SUBMIT_LOOKS_10;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_11" )
	{
		result = eQuestId::VOTE_ON_LOOKS_11;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_LEATHER_12" )
	{
		result = eQuestId::SUBMIT_WITHOUT_LEATHER_12;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_GRAY_13" )
	{
		result = eQuestId::SUBMIT_WITHOUT_GRAY_13;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_14" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_14;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_15" )
	{
		result = eQuestId::SUBMIT_LOOKS_15;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_16" )
	{
		result = eQuestId::VOTE_ON_LOOKS_16;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_LEATHER_17" )
	{
		result = eQuestId::SUBMIT_WITHOUT_LEATHER_17;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_WHITE_18" )
	{
		result = eQuestId::SUBMIT_WITHOUT_WHITE_18;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_19" )
	{
		result = eQuestId::OBTAIN_ITEMS_19;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_20" )
	{
		result = eQuestId::SUBMIT_LOOKS_20;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_21" )
	{
		result = eQuestId::VOTE_ON_LOOKS_21;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_COTTON_22" )
	{
		result = eQuestId::SUBMIT_WITHOUT_COTTON_22;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_23" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_23;
	}
	else if ( aQuestId == "SUBMIT_WITH_WOOL_24" )
	{
		result = eQuestId::SUBMIT_WITH_WOOL_24;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_25" )
	{
		result = eQuestId::SUBMIT_LOOKS_25;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_26" )
	{
		result = eQuestId::VOTE_ON_LOOKS_26;
	}
	else if ( aQuestId == "SUBMIT_WITH_LEAHTER_27" )
	{
		result = eQuestId::SUBMIT_WITH_LEAHTER_27;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_28" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_28;
	}
	else if ( aQuestId == "SUBMIT_WITH_FLORAL_29" )
	{
		result = eQuestId::SUBMIT_WITH_FLORAL_29;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_30" )
	{
		result = eQuestId::SUBMIT_LOOKS_30;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_31" )
	{
		result = eQuestId::VOTE_ON_LOOKS_31;
	}
	else if ( aQuestId == "SUBMIT_WITH_DENIM_32" )
	{
		result = eQuestId::SUBMIT_WITH_DENIM_32;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_33" )
	{
		result = eQuestId::OBTAIN_ITEMS_33;
	}
	else if ( aQuestId == "SUBMIT_WITH_STRIPED_34" )
	{
		result = eQuestId::SUBMIT_WITH_STRIPED_34;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_35" )
	{
		result = eQuestId::SUBMIT_LOOKS_35;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_36" )
	{
		result = eQuestId::VOTE_ON_LOOKS_36;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_BLACK_37" )
	{
		result = eQuestId::SUBMIT_WITHOUT_BLACK_37;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_38" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_38;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_39" )
	{
		result = eQuestId::SUBMIT_LOOKS_39;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_40" )
	{
		result = eQuestId::OBTAIN_ITEMS_40;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_41" )
	{
		result = eQuestId::VOTE_ON_LOOKS_41;
	}
	else if ( aQuestId == "SUBMIT_WITH_LEAHTER_42" )
	{
		result = eQuestId::SUBMIT_WITH_LEAHTER_42;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_43" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_43;
	}
	else if ( aQuestId == "SUBMIT_WITH_YELLOW_44" )
	{
		result = eQuestId::SUBMIT_WITH_YELLOW_44;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_45" )
	{
		result = eQuestId::OBTAIN_ITEMS_45;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_46" )
	{
		result = eQuestId::VOTE_ON_LOOKS_46;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_COTTON_47" )
	{
		result = eQuestId::SUBMIT_WITHOUT_COTTON_47;
	}
	else if ( aQuestId == "SUBMIT_WITH_LEAHTER_48" )
	{
		result = eQuestId::SUBMIT_WITH_LEAHTER_48;
	}
	else if ( aQuestId == "SUBMIT_WITH_BLUE_49" )
	{
		result = eQuestId::SUBMIT_WITH_BLUE_49;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_50" )
	{
		result = eQuestId::OBTAIN_ITEMS_50;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_51" )
	{
		result = eQuestId::VOTE_ON_LOOKS_51;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_BLACK_52" )
	{
		result = eQuestId::SUBMIT_WITHOUT_BLACK_52;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_LEATHER_53" )
	{
		result = eQuestId::SUBMIT_WITHOUT_LEATHER_53;
	}
	else if ( aQuestId == "SUBMIT_WITH_BLACK_LEATHER_54" )
	{
		result = eQuestId::SUBMIT_WITH_BLACK_LEATHER_54;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_55" )
	{
		result = eQuestId::OBTAIN_ITEMS_55;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_56" )
	{
		result = eQuestId::VOTE_ON_LOOKS_56;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_BLACK_57" )
	{
		result = eQuestId::SUBMIT_WITHOUT_BLACK_57;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_LEATHER_58" )
	{
		result = eQuestId::SUBMIT_WITHOUT_LEATHER_58;
	}
	else if ( aQuestId == "SUBMIT_WITH_BLUE_DENIM_59" )
	{
		result = eQuestId::SUBMIT_WITH_BLUE_DENIM_59;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_60" )
	{
		result = eQuestId::OBTAIN_ITEMS_60;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_61" )
	{
		result = eQuestId::VOTE_ON_LOOKS_61;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_BLACK_62" )
	{
		result = eQuestId::SUBMIT_WITHOUT_BLACK_62;
	}
	else if ( aQuestId == "SUBMIT_WITH_DENIM_63" )
	{
		result = eQuestId::SUBMIT_WITH_DENIM_63;
	}
	else if ( aQuestId == "SUBMIT_CENTRAL_PARK_64" )
	{
		result = eQuestId::SUBMIT_CENTRAL_PARK_64;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_65" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_65;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_66" )
	{
		result = eQuestId::VOTE_ON_LOOKS_66;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_WHITE_67" )
	{
		result = eQuestId::SUBMIT_WITHOUT_WHITE_67;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_68" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_68;
	}
	else if ( aQuestId == "SUBMIT_ROOFTOP_CAFE_69" )
	{
		result = eQuestId::SUBMIT_ROOFTOP_CAFE_69;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_70" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_70;
	}
	else if ( aQuestId == "WISH_ITEM_71" )
	{
		result = eQuestId::WISH_ITEM_71;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_WHITE_72" )
	{
		result = eQuestId::SUBMIT_WITHOUT_WHITE_72;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_73" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_73;
	}
	else if ( aQuestId == "SUBMIT_TIMES_SQUARE_74" )
	{
		result = eQuestId::SUBMIT_TIMES_SQUARE_74;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_75" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_75;
	}
	else if ( aQuestId == "WISH_ITEM_76" )
	{
		result = eQuestId::WISH_ITEM_76;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_WHITE_77" )
	{
		result = eQuestId::SUBMIT_WITHOUT_WHITE_77;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_78" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_78;
	}
	else if ( aQuestId == "SUBMIT_NIGHT_CLUB_79" )
	{
		result = eQuestId::SUBMIT_NIGHT_CLUB_79;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_80" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_80;
	}
	else if ( aQuestId == "LIKE_LOOK_81" )
	{
		result = eQuestId::LIKE_LOOK_81;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_GRAY_82" )
	{
		result = eQuestId::SUBMIT_WITHOUT_GRAY_82;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_83" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_83;
	}
	else if ( aQuestId == "SUBMIT_MET_MUSEUM_84" )
	{
		result = eQuestId::SUBMIT_MET_MUSEUM_84;
	}
	else if ( aQuestId == "SUBMIT_WITH_NEW_85" )
	{
		result = eQuestId::SUBMIT_WITH_NEW_85;
	}
	else if ( aQuestId == "LIKE_LOOK_86" )
	{
		result = eQuestId::LIKE_LOOK_86;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_GRAY_87" )
	{
		result = eQuestId::SUBMIT_WITHOUT_GRAY_87;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_88" )
	{
		result = eQuestId::OBTAIN_ITEMS_88;
	}
	else if ( aQuestId == "SUBMIT_RESTAURANT_89" )
	{
		result = eQuestId::SUBMIT_RESTAURANT_89;
	}
	else if ( aQuestId == "SUBMIT_LOOKS_90" )
	{
		result = eQuestId::SUBMIT_LOOKS_90;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_MAKEUP_91" )
	{
		result = eQuestId::SUBMIT_WITHOUT_MAKEUP_91;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_GRAY_92" )
	{
		result = eQuestId::SUBMIT_WITHOUT_GRAY_92;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_93" )
	{
		result = eQuestId::OBTAIN_ITEMS_93;
	}
	else if ( aQuestId == "SUBMIT_MUSIC_VENUE_94" )
	{
		result = eQuestId::SUBMIT_MUSIC_VENUE_94;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_95" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_95;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_MAKEUP_96" )
	{
		result = eQuestId::SUBMIT_WITHOUT_MAKEUP_96;
	}
	else if ( aQuestId == "SUBMIT_WITH_DENIM_97" )
	{
		result = eQuestId::SUBMIT_WITH_DENIM_97;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_98" )
	{
		result = eQuestId::OBTAIN_ITEMS_98;
	}
	else if ( aQuestId == "SUBMIT_STONE_STREET_99" )
	{
		result = eQuestId::SUBMIT_STONE_STREET_99;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_100" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_100;
	}
	else if ( aQuestId == "SUBMIT_WITHOUT_MAKEUP_101" )
	{
		result = eQuestId::SUBMIT_WITHOUT_MAKEUP_101;
	}
	else if ( aQuestId == "SUBMIT_WITH_DENIM_102" )
	{
		result = eQuestId::SUBMIT_WITH_DENIM_102;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_103" )
	{
		result = eQuestId::OBTAIN_ITEMS_103;
	}
	else if ( aQuestId == "SUBMIT_BALLROOM_104" )
	{
		result = eQuestId::SUBMIT_BALLROOM_104;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_105" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_105;
	}
	else if ( aQuestId == "VOTE_ON_LOOKS_106" )
	{
		result = eQuestId::VOTE_ON_LOOKS_106;
	}
	else if ( aQuestId == "SUBMIT_WITH_LEAHTER_107" )
	{
		result = eQuestId::SUBMIT_WITH_LEAHTER_107;
	}
	else if ( aQuestId == "OBTAIN_ITEMS_108" )
	{
		result = eQuestId::OBTAIN_ITEMS_108;
	}
	else if ( aQuestId == "SUBMIT_COURTYARD_109" )
	{
		result = eQuestId::SUBMIT_COURTYARD_109;
	}
	else if ( aQuestId == "SUBMIT_WITH_TREND_110" )
	{
		result = eQuestId::SUBMIT_WITH_TREND_110;
	}
	else if ( aQuestId == "TUTORIAL_1" )
	{
		result = eQuestId::TUTORIAL_1;
	}
	else if ( aQuestId == "TUTORIAL_2" )
	{
		result = eQuestId::TUTORIAL_2;
	}
	else if ( aQuestId == "TUTORIAL_3" )
	{
		result = eQuestId::TUTORIAL_3;
	}
	else if ( aQuestId == "TUTORIAL_4" )
	{
		result = eQuestId::TUTORIAL_4;
	}
	else if ( aQuestId == "TUTORIAL_5" )
	{
		result = eQuestId::TUTORIAL_5;
	}
	else if (aQuestId == "PUBLISH_AN_ITEM")
	{
		result = eQuestId::PUBLISH_AN_ITEM;
	}

	return result;
}

std::string DataTypesHelper::getQuestIdFromEnum( eQuestId aId )
{
	std::string result;

	switch ( aId )
	{
		case eQuestId::VOTE_ON_LOOKS_1:
			result = "VOTE_ON_LOOKS_1";
			break;
		case eQuestId::SUBMIT_WITHOUT_COTTON_2:
			result = "SUBMIT_WITHOUT_COTTON_2";
			break;
		case eQuestId::SUBMIT_WITH_NEW_3:
			result = "SUBMIT_WITH_NEW_3";
			break;
		case eQuestId::OBTAIN_ITEMS_4:
			result = "OBTAIN_ITEMS_4";
			break;
		case eQuestId::SUBMIT_LOOKS_5:
			result = "SUBMIT_LOOKS_5";
			break;
		case eQuestId::VOTE_ON_LOOKS_6:
			result = "VOTE_ON_LOOKS_6";
			break;
		case eQuestId::SUBMIT_WITHOUT_COTTON_7:
			result = "SUBMIT_WITHOUT_COTTON_7";
			break;
		case eQuestId::SUBMIT_WITH_NEW_8:
			result = "SUBMIT_WITH_NEW_8";
			break;
		case eQuestId::SUBMIT_WITH_TREND_9:
			result = "SUBMIT_WITH_TREND_9";
			break;
		case eQuestId::SUBMIT_LOOKS_10:
			result = "SUBMIT_LOOKS_10";
			break;
		case eQuestId::VOTE_ON_LOOKS_11:
			result = "VOTE_ON_LOOKS_11";
			break;
		case eQuestId::SUBMIT_WITHOUT_LEATHER_12:
			result = "SUBMIT_WITHOUT_LEATHER_12";
			break;
		case eQuestId::SUBMIT_WITHOUT_GRAY_13:
			result = "SUBMIT_WITHOUT_GRAY_13";
			break;
		case eQuestId::SUBMIT_WITH_NEW_14:
			result = "SUBMIT_WITH_NEW_14";
			break;
		case eQuestId::SUBMIT_LOOKS_15:
			result = "SUBMIT_LOOKS_15";
			break;
		case eQuestId::VOTE_ON_LOOKS_16:
			result = "VOTE_ON_LOOKS_16";
			break;
		case eQuestId::SUBMIT_WITHOUT_LEATHER_17:
			result = "SUBMIT_WITHOUT_LEATHER_17";
			break;
		case eQuestId::SUBMIT_WITHOUT_WHITE_18:
			result = "SUBMIT_WITHOUT_WHITE_18";
			break;
		case eQuestId::OBTAIN_ITEMS_19:
			result = "OBTAIN_ITEMS_19";
			break;
		case eQuestId::SUBMIT_LOOKS_20:
			result = "SUBMIT_LOOKS_20";
			break;
		case eQuestId::VOTE_ON_LOOKS_21:
			result = "VOTE_ON_LOOKS_21";
			break;
		case eQuestId::SUBMIT_WITHOUT_COTTON_22:
			result = "SUBMIT_WITHOUT_COTTON_22";
			break;
		case eQuestId::SUBMIT_WITH_NEW_23:
			result = "SUBMIT_WITH_NEW_23";
			break;
		case eQuestId::SUBMIT_WITH_WOOL_24:
			result = "SUBMIT_WITH_WOOL_24";
			break;
        case eQuestId::SUBMIT_LOOKS_25:
            result = "SUBMIT_LOOKS_25";
            break;
		case eQuestId::VOTE_ON_LOOKS_26:
			result = "VOTE_ON_LOOKS_26";
			break;
        case eQuestId::SUBMIT_WITH_LEAHTER_27:
            result = "SUBMIT_WITH_LEAHTER_27";
            break;
		case eQuestId::SUBMIT_WITH_NEW_28:
			result = "SUBMIT_WITH_NEW_28";
			break;
		case eQuestId::SUBMIT_WITH_FLORAL_29:
			result = "SUBMIT_WITH_FLORAL_29";
			break;
		case eQuestId::SUBMIT_LOOKS_30:
			result = "SUBMIT_LOOKS_30";
			break;
		case eQuestId::VOTE_ON_LOOKS_31:
			result = "VOTE_ON_LOOKS_31";
			break;
		case eQuestId::SUBMIT_WITH_DENIM_32:
			result = "SUBMIT_WITH_DENIM_32";
			break;
		case eQuestId::OBTAIN_ITEMS_33:
			result = "OBTAIN_ITEMS_33";
			break;
		case eQuestId::SUBMIT_WITH_STRIPED_34:
			result = "SUBMIT_WITH_STRIPED_34";
			break;
		case eQuestId::SUBMIT_LOOKS_35:
			result = "SUBMIT_LOOKS_35";
			break;
		case eQuestId::VOTE_ON_LOOKS_36:
			result = "VOTE_ON_LOOKS_36";
			break;
		case eQuestId::SUBMIT_WITHOUT_BLACK_37:
			result = "SUBMIT_WITHOUT_BLACK_37";
			break;
		case eQuestId::SUBMIT_WITH_TREND_38:
			result = "SUBMIT_WITH_TREND_38";
			break;
		case eQuestId::SUBMIT_LOOKS_39:
			result = "SUBMIT_LOOKS_39";
			break;
		case eQuestId::OBTAIN_ITEMS_40:
			result = "OBTAIN_ITEMS_40";
			break;
		case eQuestId::VOTE_ON_LOOKS_41:
			result = "VOTE_ON_LOOKS_41";
			break;
		case eQuestId::SUBMIT_WITH_LEAHTER_42:
			result = "SUBMIT_WITH_LEAHTER_42";
			break;
		case eQuestId::SUBMIT_WITH_TREND_43:
			result = "SUBMIT_WITH_TREND_43";
			break;
		case eQuestId::SUBMIT_WITH_YELLOW_44:
			result = "SUBMIT_WITH_YELLOW_44";
			break;
		case eQuestId::OBTAIN_ITEMS_45:
			result = "OBTAIN_ITEMS_45";
			break;
		case eQuestId::VOTE_ON_LOOKS_46:
			result = "VOTE_ON_LOOKS_46";
			break;
		case eQuestId::SUBMIT_WITHOUT_COTTON_47:
			result = "SUBMIT_WITHOUT_COTTON_47";
			break;
		case eQuestId::SUBMIT_WITH_LEAHTER_48:
			result = "SUBMIT_WITH_LEAHTER_48";
			break;
		case eQuestId::SUBMIT_WITH_BLUE_49:
			result = "SUBMIT_WITH_BLUE_49";
			break;
		case eQuestId::OBTAIN_ITEMS_50:
			result = "OBTAIN_ITEMS_50";
			break;
		case eQuestId::VOTE_ON_LOOKS_51:
			result = "VOTE_ON_LOOKS_51";
			break;
		case eQuestId::SUBMIT_WITHOUT_BLACK_52:
			result = "SUBMIT_WITHOUT_BLACK_52";
			break;
		case eQuestId::SUBMIT_WITHOUT_LEATHER_53:
			result = "SUBMIT_WITHOUT_LEATHER_53";
			break;
		case eQuestId::SUBMIT_WITH_BLACK_LEATHER_54:
			result = "SUBMIT_WITH_BLACK_LEATHER_54";
			break;
		case eQuestId::OBTAIN_ITEMS_55:
			result = "OBTAIN_ITEMS_55";
			break;
		case eQuestId::VOTE_ON_LOOKS_56:
			result = "VOTE_ON_LOOKS_56";
			break;
		case eQuestId::SUBMIT_WITHOUT_BLACK_57:
			result = "SUBMIT_WITHOUT_BLACK_57";
			break;
		case eQuestId::SUBMIT_WITHOUT_LEATHER_58:
			result = "SUBMIT_WITHOUT_LEATHER_58";
			break;
		case eQuestId::SUBMIT_WITH_BLUE_DENIM_59:
			result = "SUBMIT_WITH_BLUE_DENIM_59";
			break;
		case eQuestId::OBTAIN_ITEMS_60:
			result = "OBTAIN_ITEMS_60";
			break;
		case eQuestId::VOTE_ON_LOOKS_61:
			result = "VOTE_ON_LOOKS_61";
			break;
		case eQuestId::SUBMIT_WITHOUT_BLACK_62:
			result = "SUBMIT_WITHOUT_BLACK_62";
			break;
		case eQuestId::SUBMIT_WITH_DENIM_63:
			result = "SUBMIT_WITH_DENIM_63";
			break;
		case eQuestId::SUBMIT_CENTRAL_PARK_64:
			result = "SUBMIT_CENTRAL_PARK_64";
			break;
		case eQuestId::SUBMIT_WITH_NEW_65:
			result = "SUBMIT_WITH_NEW_65";
			break;
		case eQuestId::VOTE_ON_LOOKS_66:
			result = "VOTE_ON_LOOKS_66";
			break;
		case eQuestId::SUBMIT_WITHOUT_WHITE_67:
			result = "SUBMIT_WITHOUT_WHITE_67";
			break;
		case eQuestId::SUBMIT_WITH_TREND_68:
			result = "SUBMIT_WITH_TREND_68";
			break;
		case eQuestId::SUBMIT_ROOFTOP_CAFE_69:
			result = "SUBMIT_ROOFTOP_CAFE_69";
			break;
		case eQuestId::SUBMIT_WITH_NEW_70:
			result = "SUBMIT_WITH_NEW_70";
			break;
		case eQuestId::WISH_ITEM_71:
			result = "WISH_ITEM_71";
			break;
		case eQuestId::SUBMIT_WITHOUT_WHITE_72:
			result = "SUBMIT_WITHOUT_WHITE_72";
			break;
		case eQuestId::SUBMIT_WITH_TREND_73:
			result = "SUBMIT_WITH_TREND_73";
			break;
		case eQuestId::SUBMIT_TIMES_SQUARE_74:
			result = "SUBMIT_TIMES_SQUARE_74";
			break;
		case eQuestId::SUBMIT_WITH_NEW_75:
			result = "SUBMIT_WITH_NEW_75";
			break;
		case eQuestId::WISH_ITEM_76:
			result = "WISH_ITEM_76";
			break;
		case eQuestId::SUBMIT_WITHOUT_WHITE_77:
			result = "SUBMIT_WITHOUT_WHITE_77";
			break;
		case eQuestId::SUBMIT_WITH_TREND_78:
			result = "SUBMIT_WITH_TREND_78";
			break;
		case eQuestId::SUBMIT_NIGHT_CLUB_79:
			result = "SUBMIT_NIGHT_CLUB_79";
			break;
		case eQuestId::SUBMIT_WITH_NEW_80:
			result = "SUBMIT_WITH_NEW_80";
			break;
		case eQuestId::LIKE_LOOK_81:
			result = "LIKE_LOOK_81";
			break;
		case eQuestId::SUBMIT_WITHOUT_GRAY_82:
			result = "SUBMIT_WITHOUT_GRAY_82";
			break;
		case eQuestId::SUBMIT_WITH_TREND_83:
			result = "SUBMIT_WITH_TREND_83";
			break;
		case eQuestId::SUBMIT_MET_MUSEUM_84:
			result = "SUBMIT_MET_MUSEUM_84";
			break;
		case eQuestId::SUBMIT_WITH_NEW_85:
			result = "SUBMIT_WITH_NEW_85";
			break;
		case eQuestId::LIKE_LOOK_86:
			result = "LIKE_LOOK_86";
			break;
		case eQuestId::SUBMIT_WITHOUT_GRAY_87:
			result = "SUBMIT_WITHOUT_GRAY_87";
			break;
		case eQuestId::OBTAIN_ITEMS_88:
			result = "OBTAIN_ITEMS_88";
			break;
		case eQuestId::SUBMIT_RESTAURANT_89:
			result = "SUBMIT_RESTAURANT_89";
			break;
		case eQuestId::SUBMIT_LOOKS_90:
			result = "SUBMIT_LOOKS_90";
			break;
		case eQuestId::SUBMIT_WITHOUT_MAKEUP_91:
			result = "SUBMIT_WITHOUT_MAKEUP_91";
			break;
		case eQuestId::SUBMIT_WITHOUT_GRAY_92:
			result = "SUBMIT_WITHOUT_GRAY_92";
			break;
		case eQuestId::OBTAIN_ITEMS_93:
			result = "OBTAIN_ITEMS_93";
			break;
		case eQuestId::SUBMIT_MUSIC_VENUE_94:
			result = "SUBMIT_MUSIC_VENUE_94";
			break;
		case eQuestId::SUBMIT_WITH_TREND_95:
			result = "SUBMIT_WITH_TREND_95";
			break;
		case eQuestId::SUBMIT_WITHOUT_MAKEUP_96:
			result = "SUBMIT_WITHOUT_MAKEUP_96";
			break;
		case eQuestId::SUBMIT_WITH_DENIM_97:
			result = "SUBMIT_WITH_DENIM_97";
			break;
		case eQuestId::OBTAIN_ITEMS_98:
			result = "OBTAIN_ITEMS_98";
			break;
		case eQuestId::SUBMIT_STONE_STREET_99:
			result = "SUBMIT_STONE_STREET_99";
			break;
		case eQuestId::SUBMIT_WITH_TREND_100:
			result = "SUBMIT_WITH_TREND_100";
			break;
		case eQuestId::SUBMIT_WITHOUT_MAKEUP_101:
			result = "SUBMIT_WITHOUT_MAKEUP_101";
			break;
		case eQuestId::SUBMIT_WITH_DENIM_102:
			result = "SUBMIT_WITH_DENIM_102";
			break;
		case eQuestId::OBTAIN_ITEMS_103:
			result = "OBTAIN_ITEMS_103";
			break;
		case eQuestId::SUBMIT_BALLROOM_104:
			result = "SUBMIT_BALLROOM_104";
			break;
		case eQuestId::SUBMIT_WITH_TREND_105:
			result = "SUBMIT_WITH_TREND_105";
			break;
		case eQuestId::VOTE_ON_LOOKS_106:
			result = "VOTE_ON_LOOKS_106";
			break;
		case eQuestId::SUBMIT_WITH_LEAHTER_107:
			result = "SUBMIT_WITH_LEAHTER_107";
			break;
		case eQuestId::OBTAIN_ITEMS_108:
			result = "OBTAIN_ITEMS_108";
			break;
		case eQuestId::SUBMIT_COURTYARD_109:
			result = "SUBMIT_COURTYARD_109";
			break;
		case eQuestId::SUBMIT_WITH_TREND_110:
			result = "SUBMIT_WITH_TREND_110";
			break;
		case eQuestId::TUTORIAL_1:
			result = "TUTORIAL_1";
			break;
		case eQuestId::TUTORIAL_2:
			result = "TUTORIAL_2";
			break;
		case eQuestId::TUTORIAL_3:
			result = "TUTORIAL_3";
			break;
		case eQuestId::TUTORIAL_4:
			result = "TUTORIAL_4";
			break;
		case eQuestId::TUTORIAL_5:
			result = "TUTORIAL_5";
			break;
		case eQuestId::PUBLISH_AN_ITEM:
			result = "PUBLISH_AN_ITEM";
			break;
			 
	}

	return result;
}

DataTypesHelper::eQuestSaveKey DataTypesHelper::getQuestSaveKeyFromString( const std::string& aQuestSaveId )
{
	eQuestSaveKey result = eQuestSaveKey::UNDEFINED;

	if ( aQuestSaveId == "unique_id" )
	{
		result = eQuestSaveKey::UNIQUE_ID;
	}
	else if ( aQuestSaveId == "quest_state" )
	{
		result = eQuestSaveKey::QUEST_STATE;
	}
	else if ( aQuestSaveId == "current_events_count" )
	{
		result = eQuestSaveKey::CURRENT_EVENTS_COUNT;
	}

	return result;
}

std::string DataTypesHelper::getStringFromQuestSaveKey( eQuestSaveKey aQuestSaveKey )
{
	std::string result;

	switch ( aQuestSaveKey )
	{
		case eQuestSaveKey::UNIQUE_ID:
			result = "unique_id";
			break;
		case eQuestSaveKey::QUEST_STATE:
			result = "challenge_state";
			break;
		case eQuestSaveKey::CURRENT_EVENTS_COUNT:
			result = "current_events_count";
			break;
	}

	return result;
}

sEventFormatedRequirementInfo DataTypesHelper::formateRequirementInfo(sEventRequirementInfo* aReqInfo)
{
	sEventFormatedRequirementInfo eventReq;

	if (aReqInfo)
	{
		auto& filters = eventReq.filters;

		auto result = DataHelper::rightShift(aReqInfo->lfilterColor);
		if (!result.empty())
		{
			filters.insert(std::make_pair(eMainSubfilterType::COLOR, std::move(result)));
		}

		result = DataHelper::rightShift(aReqInfo->lfilterFabric);
		if (!result.empty())
		{
			filters.insert(std::make_pair(eMainSubfilterType::FABRIC, std::move(result)));
		}

		result = DataHelper::rightShift(aReqInfo->lfilterPattern);
		if (!result.empty())
		{
			filters.insert(std::make_pair(eMainSubfilterType::PATTERN, std::move(result)));
		}

		result = DataHelper::rightShift(aReqInfo->lfilterStyle);
		if (!result.empty())
		{
			filters.insert(std::make_pair(eMainSubfilterType::STYLE, std::move(result)));
		}

		result = DataHelper::rightShift(aReqInfo->lfilterCustom);
		if (!result.empty())
		{
			eventReq.subCategory = std::move(result);
		}

		eventReq.lookType = aReqInfo->lookType;
		eventReq.lookSet = aReqInfo->lookSet;
	}

	return eventReq;
}

float DataTypesHelper::getBonusStarsCountForLook(const sPlayerStyleInfo *const aInfo)
{
	float result = 0.0f;

	if ( aInfo )
	{
		auto bonus = DM->getBonusInfo();
		for (auto& lookBonuses : aInfo->lookBonuses)
		{
			result += bonus[lookBonuses.first];
		}

		for (auto& look : aInfo->playerStyle.looks)
		{
			auto lookInfo = DM->getLookMetaData(look.second);

			if (lookInfo != nullptr && lookInfo->effectType == eEffectType::BONUS_STARS)
			{
				result += static_cast<float>(lookInfo->effectCount) / 100.0f;
			}
		}
	}

	return result;
}

void DataTypesHelper::parseEventDifficultyInfo(const rapidjson::Value& aJsonValue, sEventDifficultyInfo& aInfo)
{
	if (aJsonValue.IsObject())
	{
		if (aJsonValue.HasMember("label_str"))
		{
			if (aJsonValue["label_str"].IsString())
			{
				aInfo.labelStr = aJsonValue["label_str"].GetString();
			}
		}

		if (aJsonValue.HasMember("color"))
		{
			if (aJsonValue["color"].IsArray())
			{
				auto colorArray = aJsonValue["color"].GetArray();
				int counter = 0;

				for (rapidjson::Value::ConstValueIterator valIt = colorArray.Begin(); valIt != colorArray.End(); valIt++)
				{
					if (valIt->IsInt())
					{
						if (counter == 0)
						{
							aInfo.color.r = valIt->GetInt();
						}
						else if (counter == 1)
						{
							aInfo.color.g = valIt->GetInt();
						}
						else
						{
							aInfo.color.b = valIt->GetInt();
						}

						counter++;
					}
				}
			}
		}
	}
}

void DataTypesHelper::initMetaFromParams(sLookMetaData* aMeta, const BValueMap& aParams)
{
	if (aMeta && !aParams.empty())
	{
		auto findIt = aParams.find("id");
		if (findIt != aParams.end())
		{
			aMeta->lookID = findIt->second.getString();
		}

		findIt = aParams.find("ltype");
		if (findIt != aParams.end())
		{
			aMeta->lookType = static_cast<eLookType>(findIt->second.getInt());
		}

		findIt = aParams.find("lfcustom");
		if (findIt != aParams.end())
		{
			aMeta->lfilterCustom = findIt->second.getInt();
		}
	}
}
