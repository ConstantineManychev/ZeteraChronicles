#include "Helpers/NodeHelper.h"
#include "BCommonHelper.h"

_USEB

Vec2 NodeHelper::getWorldPosition(const Node* aTarget)
{
    Vec2 position{0.0f, 0.0f};
    if (aTarget && aTarget->getParent())
    {
        position = aTarget->getParent()->convertToWorldSpace(aTarget->getPosition());
    }
    return position;
}


void NodeHelper::stopAllActionsInNodes(Node* aMainNode)
{
    aMainNode->stopAllActions();

    for (auto child : aMainNode->getChildren())
    {
        stopAllActionsInNodes(child);
    }
}

Node* NodeHelper::getChild(const std::string& aPath, Node* aParent)
{
    Node* container = aParent;
    auto containersList = BCHelper::getSplitStringsVecWithSeparator(aPath, "|", false);
    for (auto containerName : containersList)
    {
        container = container->getChildByName(containerName);
        if (container == nullptr)
        {
            break;
        }
    }
    return container;
}

void NodeHelper::scaleDownNodeToContainerSize(Node* aNode, Node* aContainer, bool aIsEnlargeIcon)
{
    if (aContainer && aNode)
    {
        const auto containerSize = aContainer->getContentSize();
        const auto iconSize = aNode->getContentSize();

        const float horizontalScale = containerSize.width / iconSize.width;
        const float verticalScale = containerSize.height / iconSize.height;
        const float minScale = (horizontalScale < verticalScale) ? (horizontalScale) : (verticalScale);

        if (minScale < 1.0f || aIsEnlargeIcon)
        {
            aNode->setScale(minScale);
        }
    }
}

Vec2 NodeHelper::convertPosToNodeTarget(Node* aAnchor, Node* aTarget)
{
    Vec2 result;

    if (aAnchor)
    {
        result = aAnchor->getPosition();
        auto parentAnchor = aAnchor->getParent();
        if (parentAnchor)
        {
            result = parentAnchor->convertToWorldSpace(result);

            if (aTarget)
            {
                auto targetParent = aTarget->getParent();
                if (targetParent)
                {
                    result = targetParent->convertToNodeSpace(result);
                }
            }
        }
    }

    return result;
}


void NodeHelper::setCOpacityAllChildren(Node* aParent, bool isEnabled)
{
    if (aParent)
    {
        aParent->setCascadeOpacityEnabled(isEnabled);

        auto& allChildren = aParent->getChildren();

        for (auto child : allChildren)
        {
            NodeHelper::setCOpacityAllChildren(child, isEnabled);
        }
    }
}

void NodeHelper::scaleDownNodeIfCropping(Node* aNodeToScale, Node* aNodeToCheckIntersect)
{
    if (aNodeToScale && aNodeToCheckIntersect)
    {
        auto nodeToScaleBox = aNodeToScale->getBoundingBox();
        auto nodeToCheckBox = aNodeToCheckIntersect->getBoundingBox();

        if (nodeToScaleBox.intersectsRect(nodeToCheckBox))
        {
            Node* rightSideNode = nullptr;
            Node* topSideNode = nullptr;
            Node* leftSideNode = nullptr;
            Node* downSideNode = nullptr;

            float minIntersectSize = std::numeric_limits<float>::max();

            if (nodeToScaleBox.getMaxX() > nodeToCheckBox.getMaxX())
            {
                rightSideNode = aNodeToScale;
                leftSideNode = aNodeToCheckIntersect;
            }
            else
            {
                rightSideNode = aNodeToCheckIntersect;
                leftSideNode = aNodeToScale;
            }

            if (nodeToScaleBox.getMaxY() > nodeToCheckBox.getMaxY())
            {
                topSideNode = aNodeToScale;
                downSideNode = aNodeToCheckIntersect;
            }
            else
            {
                topSideNode = aNodeToCheckIntersect;
                downSideNode = aNodeToScale;
            }

            if (topSideNode && downSideNode && rightSideNode && leftSideNode)
            {
                auto topNodeBox = topSideNode->getBoundingBox();
                auto downNodeBox = downSideNode->getBoundingBox();
                auto leftNodeBox = leftSideNode->getBoundingBox();
                auto rightNodeBox = rightSideNode->getBoundingBox();

                bool isNodeRectInside = true;
                bool scaleByWidth = false;

                if (topNodeBox.getMinY() > downNodeBox.getMinY())
                {
                    isNodeRectInside = false;

                    minIntersectSize = abs(topNodeBox.getMinY() - downNodeBox.getMaxY());
                }

                if (rightNodeBox.getMinX() > leftNodeBox.getMinX())
                {
                    isNodeRectInside = false;

                    float distance = abs(rightNodeBox.getMinX() - leftNodeBox.getMaxX());

                    if (distance < minIntersectSize)
                    {
                        scaleByWidth = true;
                        minIntersectSize = distance;
                    }
                }

                if (!isNodeRectInside)
                {
                    auto size = nodeToScaleBox.size;

                    minIntersectSize *= 2.0f;

                    float scaling = scaleByWidth ? (size.width - minIntersectSize) / size.width : (size.height - minIntersectSize) / size.height;

                    aNodeToScale->setScale(aNodeToScale->getScale() * scaling);
                }
            }
        }
    }
}

Vec2 NodeHelper::convertPosFromTo(const Vec2& aPosition, const Node* aNode, const Node* aFinalParent)
{
	Vec2 answer = aPosition;

	if (aNode && aNode != aFinalParent)
	{
		auto parentNode = aNode->getParent();

		if (parentNode)
		{
			auto contSize = parentNode->getContentSize();
			auto anchPoint = parentNode->getAnchorPoint();

			answer = answer + parentNode->getPosition() - Vec2(contSize.width * anchPoint.x, contSize.height * anchPoint.y);

			answer = convertPosFromTo(answer, parentNode, aFinalParent);

		}
	}

	return answer;
}

float NodeHelper::getSpaceWidthInLabel(Label * aLabel)
{
	float result = 0.0f;

    if (aLabel)
    {
        auto string = aLabel->getString();
        aLabel->setString(" ");
        result = aLabel->getContentSize().width;
        aLabel->setString(string);
    }

	return result;
}

float NodeHelper::getDistanceBtwNodes(Node* aFirstNode, Node* aSecondNode)
{
	float res = 0.0f;

	if (aFirstNode && aSecondNode)
	{
		auto leftSide = aFirstNode->getPositionX();
		auto bbox = aFirstNode->getBoundingBox();
		auto anchor = aFirstNode->getAnchorPoint();
		if (anchor == Vec2::ANCHOR_BOTTOM_LEFT || anchor == Vec2::ANCHOR_MIDDLE_LEFT || anchor == Vec2::ANCHOR_TOP_LEFT)
		{
			leftSide += bbox.size.width;
		}
		else if (anchor == Vec2::ANCHOR_MIDDLE_BOTTOM || anchor == Vec2::ANCHOR_MIDDLE || anchor == Vec2::ANCHOR_MIDDLE_TOP)
		{
			leftSide += bbox.size.width / 2.0f;
		}

		auto rightSide = aSecondNode->getPositionX();
		bbox = aSecondNode->getBoundingBox();
		anchor = aSecondNode->getAnchorPoint();
		if (anchor == Vec2::ANCHOR_BOTTOM_RIGHT || anchor == Vec2::ANCHOR_MIDDLE_RIGHT || anchor == Vec2::ANCHOR_TOP_RIGHT)
		{
			rightSide -= bbox.size.width;
		}
		else if (anchor == Vec2::ANCHOR_MIDDLE_BOTTOM || anchor == Vec2::ANCHOR_MIDDLE || anchor == Vec2::ANCHOR_MIDDLE_TOP)
		{
			rightSide -= bbox.size.width / 2.0f;
		}

		res = rightSide - leftSide;
	}

	return res;
}

float NodeHelper::getNodeSidePosX(Node* aNode, bool aIsLeftSide)
{
	float res = 0.0f;

	if (aNode)
	{
		res = aNode->getPositionX();
		auto bbox = aNode->getBoundingBox();
		auto anchor = aNode->getAnchorPoint();

		if (aIsLeftSide)
		{
			if (anchor == Vec2::ANCHOR_BOTTOM_LEFT || anchor == Vec2::ANCHOR_MIDDLE_LEFT || anchor == Vec2::ANCHOR_TOP_LEFT)
			{
				res -= bbox.size.width;
			}
			else if (anchor == Vec2::ANCHOR_MIDDLE_BOTTOM || anchor == Vec2::ANCHOR_MIDDLE || anchor == Vec2::ANCHOR_MIDDLE_TOP)
			{
				res -= bbox.size.width / 2.0f;
			}
		}
		else
		{
			if (anchor == Vec2::ANCHOR_BOTTOM_LEFT || anchor == Vec2::ANCHOR_MIDDLE_LEFT || anchor == Vec2::ANCHOR_TOP_LEFT)
			{
				res += bbox.size.width;
			}
			else if (anchor == Vec2::ANCHOR_MIDDLE_BOTTOM || anchor == Vec2::ANCHOR_MIDDLE || anchor == Vec2::ANCHOR_MIDDLE_TOP)
			{
				res += bbox.size.width / 2.0f;
			}
		}
	}

	return res;
}

float NodeHelper::getNodeSidePosY(Node * aNode, bool aIsDownSide)
{
	float res = 0.0f;

	if (aNode)
	{
		res = aNode->getPositionY();
		auto bbox = aNode->getBoundingBox();
		auto anchor = aNode->getAnchorPoint();

		if (aIsDownSide)
		{
			if (anchor == Vec2::ANCHOR_TOP_LEFT || anchor == Vec2::ANCHOR_MIDDLE_TOP || anchor == Vec2::ANCHOR_TOP_RIGHT)
			{
				res -= bbox.size.height;
			}
			else if (anchor == Vec2::ANCHOR_MIDDLE_LEFT || anchor == Vec2::ANCHOR_MIDDLE || anchor == Vec2::ANCHOR_MIDDLE_RIGHT)
			{
				res -= bbox.size.height / 2.0f;
			}
		}
		else
		{
			if (anchor == Vec2::ANCHOR_BOTTOM_LEFT || anchor == Vec2::ANCHOR_MIDDLE_BOTTOM || anchor == Vec2::ANCHOR_BOTTOM_RIGHT)
			{
				res += bbox.size.height;
			}
			else if (anchor == Vec2::ANCHOR_MIDDLE_LEFT || anchor == Vec2::ANCHOR_MIDDLE || anchor == Vec2::ANCHOR_MIDDLE_RIGHT)
			{
				res += bbox.size.height / 2.0f;
			}
		}
	}

	return res;
}

void NodeHelper::decreaseFontSizeToFitTheLine(Label* aLabel, int aLinesCount)
{
    if (aLabel && aLinesCount > 0)
    {
        auto ttf = aLabel->getTTFConfig();
        float originalSize = ttf.fontSize;

        while (aLabel->getStringNumLines() > aLinesCount)
        {
            ttf.fontSize -= 1.0f;
            if (ttf.fontSize <= 0.0f)
            {
                ttf.fontSize = originalSize;
                aLabel->setTTFConfig(ttf);
                break;
            }

            aLabel->setTTFConfig(ttf);
        }
    }
}
