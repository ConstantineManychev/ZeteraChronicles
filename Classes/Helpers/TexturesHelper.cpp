#include "TexturesHelper.h"
#include "SceneHelper.h"
#include "NodeHelper.h"
#include "BTCacheWrapper.h"
#include "Managers/GameDirector.h"
#include "BGameManager.h"
#include "Managers/Players/PlayerProfile.h"
#include "Views/SimpleViews/DesignerView/Components/ColorPickerIconController.h"
#include "Managers/Data/DataManager.h"

_USEB

void TexturesHelper::setTexture(Node* aIcon, const sLookIconData* aIconData)
{
    auto sprite = dynamic_cast<Sprite*>(aIcon);
    auto img = dynamic_cast<ui::ImageView*>(aIcon);
    if (aIconData && aIconData->isLoaded)
    {
        if (aIconData->iconURL.empty())
        {
            BTCWrapper->loadTexturePackFile(GET_RESOURCE_PATH(aIconData->iconPackID));

            std::string framePath = aIconData->iconFrameID;
            if (framePath.empty())
            {
                const auto& resPath = GET_RESOURCE_PARAMS(aIconData->iconPackID);
                if (resPath.isMap())
                {
                    const auto& map = resPath.getValueMap();

                    auto findIt = map.find(aIconData->iconFrameID);
                    if (findIt != map.end())
                    {
                        framePath = findIt->second.getString();
                    }
                }
            }

            SceneHelper::setImage(aIcon, framePath);
        }
        else
        {
            if (sprite)
            {
                sprite->setBatchNode(nullptr);
                sprite->setTexture(aIconData->iconURL);
            }
            if (img)
            {
                img->loadTexture(aIconData->iconURL);
            }
        }
    }
}

void TexturesHelper::setTextureAndScale(Node* aIcon, Node* aContainer, const sLookIconData* aIconData, bool aIsEnlargeIcon)
{
    setTexture(aIcon, aIconData);
    NodeHelper::scaleDownNodeToContainerSize(aIcon, aContainer, aIsEnlargeIcon);
}

void TexturesHelper::switchIconLoadSpinner(Node * aSlot, bool aEnable)
{
    if (aSlot)
    {
        auto spinner = aSlot->getChildByName("clothes_load_spinner");
        if (spinner)
        {
            BGD->stopActionTrack(spinner, "play");
            BGD->playActionTrack(spinner, "reset_position");
            if (aEnable)
            {
                BGD->playActionTrack(spinner, "play");
            }

            spinner->setVisible(aEnable);
        }
    }
}

void TexturesHelper::setDesignerBackground(Node* aNode, const sDesignerBackground& aDesBgInfo)
{
    std::string textureId = !aDesBgInfo.name.empty() ? aDesBgInfo.name : "BG_SHOP_1_PLIST";
    auto resPath = GET_RESOURCE_PATH(textureId);
    BTCWrapper->loadTexturePackFile(resPath);

    auto bgSprite = dynamic_cast<Sprite*>(aNode);
    if (bgSprite)
    {
        bgSprite->setBatchNode(nullptr);
        bgSprite->setTexture(resPath);
        bgSprite->setVisible(true);
    } 
    else
    {
        auto bgLayout = dynamic_cast<ui::Layout* >(aNode);
        if (bgLayout)
        {
            bgLayout->setBackGroundImage(resPath);
        }
    }
}

void TexturesHelper::setBackground(Node* aBackgroundNode, const std::string& aLocationID)
{
    auto locInfo = DM->getLocationInfoByID(aLocationID);
    if (locInfo)
    {
        auto resPath = GET_RESOURCE_PATH(locInfo->backgroundID);

        auto bgLayout = dynamic_cast<ui::Layout*>(aBackgroundNode);
        auto bgImage = dynamic_cast<ui::ImageView*>(aBackgroundNode);

        if (bgLayout)
        {
            bgLayout->setBackGroundImage(resPath);
        }
        else if (bgImage)
        {
            bgImage->loadTexture(resPath);
        }
    }
}

void TexturesHelper::updateBrandIcon(Node* aParent, const sBrandIcon& aIconData, const BValueMap& aParams)
{
    auto designerInfo = aParent->getChildByName("designer_info");
    if (designerInfo)
    {
        auto brandIcon = dynamic_cast<Sprite*>(designerInfo->getChildByName("bg"));
        if (brandIcon)
        {
            auto icnClr = aIconData.iconColor;
            auto icnBgClr = aIconData.bgColor;
            auto name = aIconData.name;

            if (name.empty())
            {
                auto end = aParams.end();
                auto param = aParams.find("default_brand_icon_color_id");
                if (param != end && param->second.isInteger())
                {
                    auto clrId = param->second.getInt();
                    icnClr = ColorPickerIconController::getColorById(clrId, eBrandIconColorizedPart::ICON_BADGE);
                }

                param = aParams.find("default_brand_icon_bg_color_id");
                if (param != end && param->second.isInteger())
                {
                    auto clrId = param->second.getInt();
                    icnBgClr = ColorPickerIconController::getColorById(clrId, eBrandIconColorizedPart::ICON_BACK);
                }

                param = aParams.find("default_brand_icon_name");
                if (param != end && param->second.isString())
                {
                    name = param->second.getString();
                }
            }

            auto color = Color3B(icnBgClr);
            auto opacity = static_cast<int>(icnBgClr.a * 255.0f);

            brandIcon->setColor(color);
            brandIcon->setOpacity(opacity);

            auto desIcon = dynamic_cast<Sprite*>(brandIcon->getChildByName("designer_icon"));
            if (desIcon)
            {
                auto color = Color3B(icnClr);
                auto opacity = static_cast<int>(icnClr.a * 255.0f);

                BTCWrapper->loadTexturePackFile(GET_RESOURCE_PATH("GUI_BRAND_ICONS_PLIST"));

                desIcon->setBatchNode(nullptr);
                desIcon->setSpriteFrame(name);

                desIcon->setColor(color);
                desIcon->setOpacity(opacity);
            }
        }
    }
}

Sprite * TexturesHelper::createSpriteWithIconData(const sLookIconData * aIconData)
{
    Sprite* result = nullptr;

    if (aIconData && aIconData->isLoaded)
    {
        if (aIconData->iconURL.empty())
        {
            BTCWrapper->loadTexturePackFile(GET_RESOURCE_PATH(aIconData->iconPackID));
            result = Sprite::createWithSpriteFrameName(aIconData->iconFrameID);
        }
        else
        {
            result = Sprite::create(aIconData->iconURL);
        }
    }

    return result;
}
