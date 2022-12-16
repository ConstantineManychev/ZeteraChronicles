#ifndef _NODEHELPER_H_
#define _NODEHELPER_H_

#include "BCommonDefines.h"
#include "2d/CCNode.h"
#include "2d/CCLabel.h"

_BSTART

class NodeHelper
{
public:
    static Vec2 getWorldPosition(const Node* aTarget);
    static void stopAllActionsInNodes(Node* aMainNode);
    static Node* getChild(const std::string& aPath, Node* aParent);
    static void scaleDownNodeToContainerSize(Node* aNode, Node* aContainer, bool aIsEnlargeIcon = false);
    static Vec2 convertPosToNodeTarget(Node* aAnchor, Node* aTarget);
    static void setCOpacityAllChildren(Node* aParent, bool isEnabled);
    static void scaleDownNodeIfCropping(Node* aNodeToScale, Node* aNodeToCheckIntersect);
	static Vec2 convertPosFromTo(const Vec2& aPosition, const Node* aParentNode, const Node* aFinalParent = nullptr);
	static float getSpaceWidthInLabel(Label* aLabel);
	static float getNodeSidePosX(Node* aNode, bool aIsLeftSide);
	static float getNodeSidePosY(Node* aNode, bool aIsDownSide);
	static float getDistanceBtwNodes(Node* aFirstNode, Node* aSecondNode);
	static void decreaseFontSizeToFitTheLine(Label* aLabel, int aLinesCount = 1);
};

_BEND

#endif // _NODEHELPER_H_
