#include "DataHelper.h"
#include "Managers/GameDirector.h"
#include "Managers/ItemSystem/ItemSystem.h"
#include "Helpers/DataTypesHelper.h"
#include "BGameManager.h"

_USEB

#define MILLION 1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN  10

bool DataHelper::hasFilterColor( const sLookInfo* lookInfo, eLookFilterColor filter )
{
    bool result = false;
    
    int filterMask = 1 << static_cast< int >( filter );
        
    if ( lookInfo->metaData.lfilterColor & filterMask )
    {
        result = true;
    }

    return result;
}
bool DataHelper::hasFilterStyle( const sLookInfo* lookInfo, eLookFilterStyle filter )
{
	bool result = false;

	int filterMask = 1 << static_cast< int >( filter );

	if( lookInfo->metaData.lfilterStyle & filterMask )
	{
		result = true;
	}

	return result;
}
bool DataHelper::hasFilterFabric( const sLookInfo* lookInfo, eLookFilterFabric filter )
{
    bool result = false;
    
    int filterMask = 1 << static_cast< int >( filter );
    
    if ( lookInfo->metaData.lfilterFabric & filterMask )
    {
        result = true;
    }
    
    return result;
}
bool DataHelper::hasFilterPattern( const sLookInfo* lookInfo, eLookFilterPattern filter )
{
    bool result = false;
    
    int filterMask = 1 << static_cast< int >( filter );
    
    if ( lookInfo->metaData.lfilterPattern & filterMask )
    {
        result = true;
    }
    
    return result;
}
void DataHelper::splitLooksMapByFilterColor( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterColor, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookFilterColor filter = eLookFilterColor::UNDEFINED; filter != eLookFilterColor::FILTER_END; )
        {
            if ( filter != eLookFilterColor::UNDEFINED )
            {
                if ( hasFilterColor( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookFilterColor >( (int)filter + 1 );
        }
    }

}
void DataHelper::splitLooksMapByFilterStyle( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterStyle, std::map< std::string, const sLookInfo* > >& resultMap )
{
	resultMap.clear();

	for( auto lookIt : looksMap )
	{
		auto lookInfo = lookIt.second;
		const std::string& lookID = lookIt.first;

		for( eLookFilterStyle filter = eLookFilterStyle::UNDEFINED; filter != eLookFilterStyle::FILTER_END; )
		{
			if( filter != eLookFilterStyle::UNDEFINED )
			{
				if( hasFilterStyle( lookInfo, filter ) )
				{
					resultMap[ filter ][ lookID ] = lookInfo;
				}
			}

			//increment
			filter = static_cast< eLookFilterStyle >( ( int )filter + 1 );
		}
	}

}
void DataHelper::splitLooksMapByFilterFabric( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterFabric, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookFilterFabric filter = eLookFilterFabric::UNDEFINED; filter != eLookFilterFabric::FILTER_END; )
        {
            if ( filter != eLookFilterFabric::UNDEFINED )
            {
                if ( hasFilterFabric( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookFilterFabric >( (int)filter + 1 );
        }
    }
    
}
void DataHelper::splitLooksMapByFilterPattern( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterPattern, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookFilterPattern filter = eLookFilterPattern::UNDEFINED; filter != eLookFilterPattern::FILTER_END; )
        {
            if ( filter != eLookFilterPattern::UNDEFINED )
            {
                if ( hasFilterPattern( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookFilterPattern >( (int)filter + 1 );
        }
    }
    
}

std::set<unsigned int> DataHelper::rightShift(unsigned int aFilter)
{
    std::set<unsigned int> result;

    for (unsigned i = 0u; aFilter >> i; ++i)
    {
        unsigned number = (aFilter >> i) & 1u;

        if (number == 1u)
        {
            result.insert(i);
        }
    }

    return result;
}

bool DataHelper::hasCustomFilterDress( const sLookInfo* lookInfo, eLookCustomFilterDress filter )
{
    bool result = false;
    
    if ( lookInfo->metaData.lookType == eLookType::DRESS )
    {
        int filterMask = 1 << static_cast< int >( filter );
        
        if ( lookInfo->metaData.lfilterCustom & filterMask )
        {
            result = true;
        }
    }
    
    return result;
}
bool DataHelper::hasCustomFilterBottom( const sLookInfo* lookInfo, eLookCustomFilterBottom filter )
{
    bool result = false;
    
    if ( lookInfo->metaData.lookType == eLookType::BOTTOM )
    {
        int filterMask = 1 << static_cast< int >( filter );
        
        if ( lookInfo->metaData.lfilterCustom & filterMask )
        {
            result = true;
        }
    }
    
    return result;
}
bool DataHelper::hasCustomFilterShoes( const sLookInfo* lookInfo, eLookCustomFilterShoes filter )
{
    bool result = false;
    
	if ( ISYSTEM->isLookTypeIsShoesType( lookInfo->metaData.lookType ) )
    {
        int filterMask = 1 << static_cast< int >( filter );
        
        if ( lookInfo->metaData.lfilterCustom & filterMask )
        {
            result = true;
        }
    }
    
    return result;
}
bool DataHelper::hasCustomFilterAccessories( const sLookInfo* lookInfo, eLookCustomFilterAccessories filter )
{
    bool result = false;
    
    if ( ISYSTEM->isLookTypeIsAccessoriesType( lookInfo->metaData.lookType ) )
    {
        int filterMask = 1 << static_cast< int >( filter );
        
        if ( lookInfo->metaData.lfilterCustom & filterMask )
        {
            result = true;
        }
    }
    
    return result;
}
bool DataHelper::hasCustomFilterTopA( const sLookInfo* lookInfo, eLookCustomFilterTopA filter )
{
    bool result = false;
    
    if ( ISYSTEM->isLookTypeIsTopAType(lookInfo->metaData.lookType) )
    {
        int filterMask = 1 << static_cast< int >( filter );
        
        if ( lookInfo->metaData.lfilterCustom & filterMask )
        {
            result = true;
        }
    }
    
    return result;
}
bool DataHelper::hasCustomFilterTopB( const sLookInfo* lookInfo, eLookCustomFilterTopB filter )
{
    bool result = false;
    
    if ( lookInfo->metaData.lookType == eLookType::TOP_B )
    {
        int filterMask = 1 << static_cast< int >( filter );
        
        if ( lookInfo->metaData.lfilterCustom & filterMask )
        {
            result = true;
        }
    }
    
    return result;
}

std::string DataHelper::getItemNameFromCustomFilter(eLookType aLookType, unsigned aFilterCustom, bool aIsFilters)
{
	std::string result;

	unsigned filter = 0;
	std::string custom;
	std::string idTemplate;

	if (aIsFilters)
	{
		idTemplate = "TT_FILTERS_%s_BTN_%s";
	}
	else
	{
		idTemplate = "TT_CATEGORY_%s_%s";
	}

	if (aFilterCustom)
	{
		filter = log2(aFilterCustom);
		BValue ID;
		std::string type;

		if (aLookType == eLookType::DRESS)
		{
			custom = DataTypesHelper::getStrFromLookCustomFilterDress(static_cast<eLookCustomFilterDress>(filter));
			type = "DRESS";
			ID.initWithFormat(idTemplate.c_str(), type.c_str(), custom.c_str());
		}
		else if (aLookType == eLookType::TOP_A || aLookType == eLookType::TOP_A_TUCKED)
		{
			custom = DataTypesHelper::getStrFromLookCustomFilterTopA(static_cast<eLookCustomFilterTopA>(filter));
			type = "TOP_A";
			ID.initWithFormat(idTemplate.c_str(), type.c_str(), custom.c_str());
		}
		else if (aLookType == eLookType::TOP_B)
		{
			custom = DataTypesHelper::getStrFromLookCustomFilterTopB(static_cast<eLookCustomFilterTopB>(filter));
			type = "TOP_B";
			ID.initWithFormat(idTemplate.c_str(), type.c_str(), custom.c_str());
		}
		else if (aLookType == eLookType::BOTTOM)
		{
			custom = DataTypesHelper::getStrFromLookCustomFilterBottom(static_cast<eLookCustomFilterBottom>(filter));
			type = "BOTTOM";
			ID.initWithFormat(idTemplate.c_str(), type.c_str(), custom.c_str());
		}
		else if (aLookType == eLookType::SHOES)
		{
			custom = DataTypesHelper::getStrFromLookCustomFilterShoes(static_cast<eLookCustomFilterShoes>(filter));
			type = "SHOES";
			ID.initWithFormat(idTemplate.c_str(), type.c_str(), custom.c_str());
		}
		else if (aLookType >= eLookType::ACC_HATS && aLookType < eLookType::MAKEUP_EYES)
		{
			custom = DataTypesHelper::getStrFromLookCustomFilterAccessories( static_cast< eLookCustomFilterAccessories >( filter ) );
			type = "ACCESSORIES";
			ID.initWithFormat( idTemplate.c_str(), type.c_str(), custom.c_str() );
		}

		result = GET_STRING(ID.getString().c_str());

		if ( result == "NO_STRING" )
		{
			idTemplate = "TT_CATEGORY_%s";
			ID.initWithFormat( idTemplate.c_str(), type.c_str() );

			result = GET_STRING( ID.getString().c_str() );
		}
	}

	return result;
}

unsigned DataHelper::log2( unsigned aValue )
{
    unsigned res = 0;
    while ( aValue > 1 )
    {
        aValue /= 2;
        res++;
    }
    return res;
}

std::string DataHelper::constructEventDescriptionLine( const sEventInfo* aInfo )
{
    std::string result;

	if (aInfo)
	{
		auto descTemplateID = aInfo->descTemplateID;
		std::string templateLine = GET_STRING(descTemplateID);	

		std::vector <std::string> qualitiesVec;

		for (auto& qualityStrID : aInfo->qualityIDs)
		{
			qualitiesVec.push_back(GET_STRING(qualityStrID));
		}

		std::string style = GET_STRING(aInfo->styleID);
		std::string action = GET_STRING(aInfo->actionID);
		BValue val;

		if (!qualitiesVec.empty())
		{
			if (descTemplateID == "TT_EV_DRESS_TEMPLATE_1")
			{
				val.initWithFormat(templateLine.c_str(), "", qualitiesVec[0].c_str(), style.c_str(), action.c_str());
			}
			else if (descTemplateID == "TT_EV_DRESS_TEMPLATE_2")
			{
				val.initWithFormat(templateLine.c_str(), "", qualitiesVec[0].c_str(), action.c_str());
			}
			else if (descTemplateID == "TT_EV_DRESS_TEMPLATE_3")
			{
				val.initWithFormat(templateLine.c_str(), "", qualitiesVec[0].c_str(), style.c_str(), action.c_str());
			}
			else if (descTemplateID == "TT_EV_DRESS_TEMPLATE_4")
			{
				val.initWithFormat(templateLine.c_str(), "", style.c_str(), action.c_str());
			}
			else if (descTemplateID == "TT_EV_DRESS_TEMPLATE_5" && qualitiesVec.size() >= 2)
			{
				val.initWithFormat(templateLine.c_str(), "", qualitiesVec[0].c_str(), qualitiesVec[1].c_str(), action.c_str());
			}

			result = val.getString();
		}
	}
	return result;
}

void DataHelper::splitLooksMapByCustomFilterDress( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterDress, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookCustomFilterDress filter = eLookCustomFilterDress::UNDEFINED; filter != eLookCustomFilterDress::FILTER_END; )
        {
            if ( filter != eLookCustomFilterDress::UNDEFINED )
            {
                if ( hasCustomFilterDress( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookCustomFilterDress >( (int)filter + 1 );
        }
    }
   
}
void DataHelper::splitLooksMapByCustomFilterBottom( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterBottom, std::map< std::string, const sLookInfo* > >& resultMap )
{
	resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookCustomFilterBottom filter = eLookCustomFilterBottom::UNDEFINED; filter != eLookCustomFilterBottom::FILTER_END; )
        {
            if ( filter != eLookCustomFilterBottom::UNDEFINED )
            {
                if ( hasCustomFilterBottom( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookCustomFilterBottom >( (int)filter + 1 );
        }
    }
   
}
void DataHelper::splitLooksMapByCustomFilterShoes( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterShoes, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookCustomFilterShoes filter = eLookCustomFilterShoes::UNDEFINED; filter != eLookCustomFilterShoes::FILTER_END; )
        {
            if ( filter != eLookCustomFilterShoes::UNDEFINED )
            {
                if ( hasCustomFilterShoes( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookCustomFilterShoes >( (int)filter + 1 );
        }
    }
 
}
void DataHelper::splitLooksMapByCustomFilterAccessories( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterAccessories, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookCustomFilterAccessories filter = eLookCustomFilterAccessories::UNDEFINED; filter != eLookCustomFilterAccessories::FILTER_END; )
        {
            if ( filter != eLookCustomFilterAccessories::UNDEFINED )
            {
                if ( hasCustomFilterAccessories( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookCustomFilterAccessories >( (int)filter + 1 );
        }
    }
}
void DataHelper::splitLooksMapByCustomFilterTopA( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterTopA, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookCustomFilterTopA filter = eLookCustomFilterTopA::UNDEFINED; filter != eLookCustomFilterTopA::FILTER_END; )
        {
            if ( filter != eLookCustomFilterTopA::UNDEFINED )
            {
                if ( hasCustomFilterTopA( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookCustomFilterTopA >( (int)filter + 1 );
        }
    }
    
}
void DataHelper::splitLooksMapByCustomFilterTopB( const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterTopB, std::map< std::string, const sLookInfo* > >& resultMap )
{
    resultMap.clear();
    
    for( auto lookIt : looksMap )
    {
        auto lookInfo = lookIt.second;
        const std::string& lookID = lookIt.first;
        
        for ( eLookCustomFilterTopB filter = eLookCustomFilterTopB::UNDEFINED; filter != eLookCustomFilterTopB::FILTER_END; )
        {
            if ( filter != eLookCustomFilterTopB::UNDEFINED )
            {
                if ( hasCustomFilterTopB( lookInfo, filter ) )
                {
                    resultMap[ filter ][ lookID ] = lookInfo;
                }
            }
            
            //increment
            filter = static_cast< eLookCustomFilterTopB >( (int)filter + 1 );
        }
    }
}

std::string DataHelper::getStrFromMainSubfilterType( eMainSubfilterType aType, bool aUseCollection)
{
	std::string result;
	switch( aType )
	{
		case eMainSubfilterType::COLOR:
			result = "COLOR";
			break;
		case eMainSubfilterType::INVENTORY:
			result = "INVENTORY";
			break;
		case eMainSubfilterType::FABRIC:
			result = "FABRIC";
			break;
		case eMainSubfilterType::PATTERN:
			result = "PATTERN";
			break;
		case eMainSubfilterType::SEASON:
			result = !aUseCollection ? "SEASON" : "COLLECTION";
			break;
		case eMainSubfilterType::STYLE:
			result = "STYLE";
			break;
        case eMainSubfilterType::QUEST:
			result = "QUEST";
            break;
        case eMainSubfilterType::SALE:
			result = "SALE";
            break;
        case eMainSubfilterType::OFFICIAL:
            result = "OFFICIAL";
			break;
	};

	return result;
}

eMainSubfilterType DataHelper::getMainSubfilterTypeFromStr(const std::string& aType, bool aUseCollection)
{
    eMainSubfilterType mainSubfilterType = eMainSubfilterType::NONE;
    if (aType == "COLOR")
    {
        mainSubfilterType = eMainSubfilterType::COLOR;
    } 
    else if (aType == "INVENTORY")
    {
        mainSubfilterType = eMainSubfilterType::INVENTORY;
    }
    else if (aType == "FABRIC")
    {
        mainSubfilterType = eMainSubfilterType::FABRIC;
    }
    else if (aType == "PATTERN")
    {
        mainSubfilterType = eMainSubfilterType::PATTERN;
    }
    else if (aType == "SEASON" || (aUseCollection && aType == "COLLECTION"))
    {
        mainSubfilterType = eMainSubfilterType::SEASON;
    }
    else if (aType == "STYLE")
    {
        mainSubfilterType = eMainSubfilterType::STYLE;
    }
    else if (aType == "QUEST")
    {
        mainSubfilterType = eMainSubfilterType::QUEST;
    }
    else if (aType == "SALE")
    {
        mainSubfilterType = eMainSubfilterType::SALE;
    }
    return mainSubfilterType;
}

std::string DataHelper::getStrFromSubfilterSortType(eSubfilteSortType aType)
{
    std::string result;
    switch (aType)
    {
    case eSubfilteSortType::SORT_POPULAR:
        result = "POPULAR";
        break;
    case eSubfilteSortType::SORT_TOP:
        result = "TOP";
        break;
    case eSubfilteSortType::SORT_NEW:
        result = "NEW";
        break;
    default:
        break;
    };

    return result;
}

std::string DataHelper::getStrFromLookCategory( eLookCategory aCategory )
{
	std::string result;
	switch( aCategory )
	{
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
	};

	return result;
}

std::string DataHelper::getIconNameFromBonusType(eBonusType aBonus)
{
	std::string result;

	switch (aBonus) {
	case eBonusType::NEW_ITEM_BONUS:
		result = "new";
		break;
	case eBonusType::BORROWED_ITEM_BONUS:
		result = "borrowed";
		break;
	case eBonusType::SEASON_ITEM_BONUS:
		result = "season";
		break;
	case eBonusType::TRENDING_ITEM_BONUS:
		result = "trending";
		break;
	default:
		break;
	}

	return result;
}

eItemLookTypeOrder DataHelper::getItemLookTypeOrderFromLookType( eLookType aLookType )
{
	eItemLookTypeOrder result = eItemLookTypeOrder::UNDEFINED;

	switch (aLookType)
	{
	case eLookType::UNDEFINED:
		result = eItemLookTypeOrder::UNDEFINED;
		break;
	case eLookType::DRESS:
		result = eItemLookTypeOrder::DRESS;
		break;
	case eLookType::TOP_A:
		result = eItemLookTypeOrder::TOP_A;
		break;
	case eLookType::TOP_A_TUCKED:
		result = eItemLookTypeOrder::TOP_A_TUCKED;
		break;
	case eLookType::TOP_B:
		result = eItemLookTypeOrder::TOP_B;
		break;
	case eLookType::BOTTOM:
		result = eItemLookTypeOrder::BOTTOM;
		break;
	case eLookType::SHOES:
		result = eItemLookTypeOrder::SHOES;
		break;
	case eLookType::BOOTS:
		result = eItemLookTypeOrder::BOOTS;
		break;
	case eLookType::ACC_HATS:
		result = eItemLookTypeOrder::ACC_HATS;
		break;
	case eLookType::ACC_GLASSES:
		result = eItemLookTypeOrder::ACC_GLASSES;
		break;
	case eLookType::ACC_JEWELRY:
		result = eItemLookTypeOrder::ACC_JEWELRY;
		break;
	case eLookType::ACC_RINGS:
		result = eItemLookTypeOrder::ACC_RINGS;
		break;
	case eLookType::ACC_BELTS:
		result = eItemLookTypeOrder::ACC_BELTS;
		break;
	case eLookType::ACC_GLOVES:
		result = eItemLookTypeOrder::ACC_GLOVES;
		break;
	case eLookType::ACC_EARRINGS:
		result = eItemLookTypeOrder::ACC_EARRINGS;
		break;
	case eLookType::ACC_HANDBAGS:
		result = eItemLookTypeOrder::ACC_HANDBAGS;
		break;
    case eLookType::ACC_NECKLACE:
        result = eItemLookTypeOrder::ACC_NECKLACE;
        break;
	case eLookType::ACC_BACKPACKS:
		result = eItemLookTypeOrder::ACC_BACKPACKS;
		break;
	case eLookType::ACC_SCARVES:
		result = eItemLookTypeOrder::ACC_SCARVES;
		break;
    case eLookType::ACC_BROOCH:
        result = eItemLookTypeOrder::ACC_BROOCH;
        break;
	case eLookType::ACC_STOCKINGS:
		result = eItemLookTypeOrder::ACC_STOCKINGS;
		break;
	case eLookType::PERFUME:
		result = eItemLookTypeOrder::PERFUME;
		break;
	case eLookType::FACE_GLITTER:
		result = eItemLookTypeOrder::FACE_GLITTER;
		break;

	default:
		break;
	}

	return result;
}

std::string DataHelper::convertInfluenceNumberToString(int aNumber)
{
	BValue resultString;

	int convertedNumber = aNumber;

	if (aNumber >= MILLION)
	{
		resultString = getInfluenceStringByComparing(aNumber, MILLION, GET_STRING("TT_MILLION"));
		
	}
	else if (aNumber >= THOUSAND * HUNDRED)
	{
		convertedNumber = aNumber / THOUSAND;

		resultString.initWithFormat("%d %s", convertedNumber, GET_STRING("TT_THOUSAND").c_str());
	}
	else
	{
		resultString = convertedNumber;
	}

	return resultString.getString();
}

std::string DataHelper::convertNumberToDecimalFracView(int aNumber)
{
    BValue formatedString;
    std::string numAsString = std::to_string(aNumber);

    if (aNumber > THOUSAND && aNumber < THOUSAND * 10)
    {
        formatedString.initWithFormat("%c.%c%s", numAsString[0], numAsString[1], GET_STRING("TT_THOUSAND").c_str());    
        numAsString = formatedString.getString();
    }
    else if (aNumber > THOUSAND * 10)
    {
        std::string number = std::to_string(aNumber / HUNDRED);

        std::size_t strSize = number.size();

        std::string base = number.substr(0, strSize - 1);
        std::string fracNumber = number.substr(strSize - 1, strSize);

        formatedString.initWithFormat("%s.%s%s", base.c_str(), fracNumber.c_str(), GET_STRING("TT_THOUSAND").c_str());
        numAsString = formatedString.getString();
    }

    return numAsString;
}
std::string DataHelper::getInfluenceStringByComparing(int aNumber, int aCompareNumber, const std::string& aLetter)
{
	BValue resultString;

	if (aNumber >= aCompareNumber)
	{
		std::string outputTemplate;

		if (aNumber >= aCompareNumber * HUNDRED)
		{
			int convertedNumber = aNumber / aCompareNumber;
			outputTemplate = "%d %s";
			resultString.initWithFormat(outputTemplate.c_str(), convertedNumber, aLetter.c_str());
		}
		else
		{
			float convertedNumber = aNumber;

			if (aNumber >= aCompareNumber * TEN)
			{
				convertedNumber = static_cast<int>(aNumber / static_cast<float>(aCompareNumber) * TEN) / static_cast<float>(TEN);
				outputTemplate = "%.1f %s";
			}
			else
			{
				convertedNumber = static_cast<int>(aNumber / static_cast<float>(aCompareNumber) * HUNDRED) / static_cast<float>(HUNDRED);
				outputTemplate = "%.2f %s";
			}

			resultString.initWithFormat(outputTemplate.c_str(), convertedNumber, aLetter.c_str());
		}

		

	}

	return resultString.getString();
}