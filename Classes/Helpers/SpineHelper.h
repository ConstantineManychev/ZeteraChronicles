#ifndef _SPINE_HELPER_H_
#define _SPINE_HELPER_H_

#include "BCommonDefines.h"
#include "BSpineAnimation.h"

#include  "spine/spine-cocos2dx.h"
#include  "spine/extension.h"


_BSTART

class SpineHelper
{
public:
	static char* mallocString (const char* str, unsigned int length = 0);
	
	static void spMeshAttachment_updateUVsCustom(spMeshAttachment* self);

	static void spMeshAttachment_updateUVsCustom2( spMeshAttachment* self, SpriteFrame* frame );


	static void addItemResource( spAtlas* atlas, const char* newPageName, const char* regionName, SpriteFrame* region );
	static void setItem(BSpineAnimation* animation, const char* skinName, const char* itemSlotName, const char* regionName );

	static void setItemTest(BSpineAnimation* animation, const char* skinName, const char* itemSlotName, const char* regionName, SpriteFrame* frame, std::vector< Vec2 >& points );

	static std::vector<std::string> getAtlasTexturesNames( const std::string& aAtlasPath, bool aIsFullPath = false );
};

_BEND

#endif