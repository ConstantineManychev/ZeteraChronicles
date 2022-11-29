#ifndef DataHelper_H
#define DataHelper_H

#include "Types/DataTypes.h"
#include "Types/DataTypesFilters.h"

namespace cocos2d {

class DataHelper
{
public:
	/* base filters */
	static std::string getStrFromMainSubfilterType(eMainSubfilterType aType, bool aUseCollection = false);
	static eMainSubfilterType getMainSubfilterTypeFromStr(const std::string& aType, bool aUseCollection = false);
	static std::string getStrFromSubfilterSortType(eSubfilteSortType aType);

	static std::string getStrFromLookCategory(eLookCategory aCategory);

	static std::string getIconNameFromBonusType(eBonusType aBonus);

	static bool hasFilterColor(const sLookInfo* lookInfo, eLookFilterColor filter);
	static bool hasFilterStyle(const sLookInfo* lookInfo, eLookFilterStyle filter);
	static bool hasFilterFabric(const sLookInfo* lookInfo, eLookFilterFabric filter);
	static bool hasFilterPattern(const sLookInfo* lookInfo, eLookFilterPattern filter);

	static void splitLooksMapByFilterColor(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterColor, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByFilterStyle(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterStyle, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByFilterFabric(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterFabric, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByFilterPattern(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookFilterPattern, std::map< std::string, const sLookInfo* > >& resultMap);
	static std::set<unsigned int> rightShift(unsigned int aFilter);

	/* custom filters */
	static bool hasCustomFilterDress(const sLookInfo* lookInfo, eLookCustomFilterDress filter);
	static bool hasCustomFilterBottom(const sLookInfo* lookInfo, eLookCustomFilterBottom filter);
	static bool hasCustomFilterShoes(const sLookInfo* lookInfo, eLookCustomFilterShoes filter);
	static bool hasCustomFilterAccessories(const sLookInfo* lookInfo, eLookCustomFilterAccessories filter);
	static bool hasCustomFilterTopA(const sLookInfo* lookInfo, eLookCustomFilterTopA filter);
	static bool hasCustomFilterTopB(const sLookInfo* lookInfo, eLookCustomFilterTopB filter);



	/* requirements struct to string conversion*/
	static std::string getItemNameFromCustomFilter(eLookType aLookType, unsigned aFilterCustom, bool aIsFilters = true);
	static std::string constructEventDescriptionLine(const sEventInfo* aInfo);
	static unsigned log2(unsigned aValue);

	static void splitLooksMapByCustomFilterDress(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterDress, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByCustomFilterBottom(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterBottom, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByCustomFilterShoes(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterShoes, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByCustomFilterAccessories(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterAccessories, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByCustomFilterTopA(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterTopA, std::map< std::string, const sLookInfo* > >& resultMap);
	static void splitLooksMapByCustomFilterTopB(const std::map< std::string, const sLookInfo* >& looksMap, std::map< eLookCustomFilterTopB, std::map< std::string, const sLookInfo* > >& resultMap);

	static eItemLookTypeOrder getItemLookTypeOrderFromLookType(eLookType aLookType);

	static std::string convertInfluenceNumberToString(int aNumber);
	static std::string getInfluenceStringByComparing(int aNumber, int aCompareNumber, const std::string& aLetter);
	static std::string convertNumberToDecimalFracView(int aNumber);
};

}

#endif
