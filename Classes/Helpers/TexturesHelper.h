#ifndef TexturesHelper_h
#define TexturesHelper_h

#include "BCommonDefines.h"
#include "BValue.h"
#include "cocos2d.h"
#include "Types/DataTypes.h"


_BSTART

class TexturesHelper
{
public:
    static void setTexture(Node* aIcon, const sLookIconData* aIconData);
    static void setTextureAndScale(Node* aIcon, Node* aContainer, const sLookIconData* aIconData, bool aIsEnlargeIcon = false);
    static void switchIconLoadSpinner(Node* aSlot, bool aEnable);

    static Sprite* createSpriteWithIconData(const sLookIconData* aIconData);
    static void updateBrandIcon(Node* aParent, const sBrandIcon& aIconData, const BValueMap& aParams);
    static void setDesignerBackground(Node* aNode, const sDesignerBackground& aDesBgInfo);
    static void setBackground(Node* aBackgroundNode, const std::string& aLocationID);
};

_BEND

#endif /* SceneHelper_h */
