#include "SpineHelper.h"

#include "BGameManager.h"

#include "spine/AtlasAttachmentLoader.h"
#include "spine/AttachmentVertices.h"
#include "spine/extension.h"
#include "spine/Atlas.c"
_USEB

char* SpineHelper::mallocString(const char* str, unsigned int length)
{
	if (length == 0)
		length = (int)strlen(str);
	char* string = MALLOC(char, length + 1);
	memcpy(string, str, length);
	string[length] = '\0';
	return string;
}

void SpineHelper::addItemResource( spAtlas* atlas, const char* newPageName, const char* regionName, SpriteFrame* region )
{
    if (region)
	{
		spAtlasPage* addPage = spAtlasPage_create(atlas, newPageName);
		spAtlasPage* lastPage = atlas->pages;

 		while (lastPage->next)
			lastPage = lastPage->next;

		lastPage->next = addPage;
	
		const Size originalSize = region->getOriginalSize();
		const Size textureSize = region->getTexture()->getContentSizeInPixels();
		const Rect rectInPix = region->getRectInPixels();
    
		addPage->atlas = atlas;
		addPage->next = 0;
		addPage->format = spAtlasFormat::SP_ATLAS_RGBA8888;
		addPage->minFilter = spAtlasFilter::SP_ATLAS_LINEAR;
		addPage->magFilter = spAtlasFilter::SP_ATLAS_LINEAR;
		addPage->uWrap = SP_ATLAS_CLAMPTOEDGE;
		addPage->vWrap = SP_ATLAS_CLAMPTOEDGE;
		addPage->rendererObject = region->getTexture();

		addPage->width =  textureSize.width;
		addPage->height = textureSize.height;

		spAtlasRegion* addRegion = spAtlasRegion_create();
		addRegion->page = addPage;
		addRegion->name = mallocString(regionName);
		
		addRegion->x = rectInPix.getMinX();
		addRegion->y = rectInPix.getMinY(); 

		addRegion->width =  rectInPix.size.width;
		addRegion->height =  rectInPix.size.height;

		addRegion->originalWidth = originalSize.width;
		addRegion->originalHeight = originalSize.height;
    
		addRegion->u = (addRegion->x / textureSize.width );
		addRegion->v = (addRegion->y / textureSize.height );
		addRegion->u2 = (addRegion->x + rectInPix.size.width) / textureSize.width;
		addRegion->v2 = (addRegion->y + rectInPix.size.height ) / textureSize.height;

		
		addRegion->rotate = region->isRotated();

		if ( region->isRotated() )
		{
			/*
			addRegion->x = rectInPix.getMinX();
			addRegion->y = rectInPix.getMinY();
			addRegion->width = textureSize.width;
			addRegion->height = textureSize.height;

			float y = rectInPix.getMinY() + rectInPix.size.width;

			addRegion->u = (addRegion->x / textureSize.width );
			addRegion->v = (y / textureSize.height );
			addRegion->u2 = (addRegion->x + rectInPix.size.height) / textureSize.width;
			addRegion->v2 = (y - rectInPix.size.width ) / textureSize.height;
			*/
		}
	
		addRegion->offsetX = region->getOffsetInPixels().x;
		addRegion->offsetY = region->getOffsetInPixels().y;

		addRegion->offsetX += (addRegion->originalWidth  - addRegion->width) / 2.0f;
		addRegion->offsetY += (addRegion->originalHeight - addRegion->height) / 2.0f + addRegion->height;

		addRegion->index = -1;
		addRegion->flip = false;
		addRegion->splits = 0;
		addRegion->pads = 0;

		spAtlasRegion* lastRegion = atlas->regions;
		while (lastRegion->next)
			lastRegion = lastRegion->next;
		lastRegion->next = addRegion;
		addRegion->next = 0;
	}
	else
	{
		log ("SpineHelper::addItemResource( SpriteFrame ) -> texture is empty region name = %s", regionName);
	}
}


void SpineHelper::setItem(BSpineAnimation* animation, const char* skinName, const char* itemSlotName, const char* regionName )
{
	spSkin* scinTmpl = spSkeletonData_findSkin(animation->getSkeleton()->data, skinName);

	int slotIndex = spSkeletonData_findSlotIndex(animation->getSkeleton()->data, itemSlotName);
	spAttachment* attach = spSkin_getAttachment(scinTmpl, slotIndex, itemSlotName);
	if ( scinTmpl && attach )
	{
		if (strlen(regionName) == 0)
		{
			regionName = itemSlotName;
		}

		spAtlasRegion* region = spAtlas_findRegion(animation->getAtlas(), regionName);
		if(region)
		{
			switch (attach->type) 
			{
			case SP_ATTACHMENT_REGION:
			{
				/*
				spRegionAttachment* attachment = SUB_CAST(spRegionAttachment, attach);
				attachment = spRegionAttachment_create(regionName);
				attachment->rendererObject = region;
				spRegionAttachment_setUVs(attachment, region->u, region->v, region->u2, region->v2, region->rotate);
				attachment->regionOffsetX = region->offsetX;
				attachment->regionOffsetY = region->offsetY;
				attachment->regionWidth = region->width;
				attachment->regionHeight = region->height;
				attachment->regionOriginalWidth = region->originalWidth;
				attachment->regionOriginalHeight = region->originalHeight;
				spRegionAttachment_updateOffset( attachment );
				*/
			}
			break;
			case SP_ATTACHMENT_MESH: 
			case SP_ATTACHMENT_LINKED_MESH:
				{
					spMeshAttachment* mesh = SUB_CAST(spMeshAttachment, attach);
					FREE(mesh->path);
					MALLOC_STR(mesh->path, region->name);
					mesh->regionU = region->u;
					mesh->regionV = region->v;
					mesh->regionU2 = region->u2;
					mesh->regionV2 = region->v2;
					mesh->regionRotate = region->rotate;
					mesh->regionOffsetX = region->offsetX;
					mesh->regionOffsetY = region->offsetY;

					mesh->regionWidth = region->width;
					mesh->regionHeight = region->height;
					mesh->regionOriginalWidth = region->originalWidth;
					mesh->regionOriginalHeight = region->originalHeight;

					delete (spine::AttachmentVertices*)mesh->rendererObject;
				
					spMeshAttachment_updateUVsCustom( mesh );
					
					spine::AttachmentVertices* attachmentVertices = new spine::AttachmentVertices((Texture2D*)region->page->rendererObject,
						mesh->super.worldVerticesLength >> 1, mesh->triangles, mesh->trianglesCount);

					V3F_C4B_T2F* vertices = attachmentVertices->_triangles->verts;
					for (int i = 0, ii = 0, nn = mesh->super.worldVerticesLength; ii < nn; ++i, ii += 2)
					{
						vertices[i].texCoords.u = mesh->uvs[ii];
						vertices[i].texCoords.v = mesh->uvs[ii + 1];
					}

					mesh->rendererObject = attachmentVertices;
				}
				break;
			}
		}
	}
	else
	{
		//log("SpineAnimationHelper::setItem -> Don't found skin whith name = %s", skinName);
		//log("SpineAnimationHelper::setItem -> Don't found attachment for slot = %s", itemSlotName);
	}
}

void SpineHelper::setItemTest(BSpineAnimation* animation, const char* skinName, const char* itemSlotName, const char* regionName, SpriteFrame* frame, std::vector< Vec2 >& points )
{
	spSkin* scinTmpl = spSkeletonData_findSkin(animation->getSkeleton()->data, skinName);

	int slotIndex = spSkeletonData_findSlotIndex(animation->getSkeleton()->data, itemSlotName);
	spAttachment* attach = spSkin_getAttachment(scinTmpl, slotIndex, itemSlotName);
	if ( scinTmpl && attach )
	{
		if (strlen(regionName) == 0)
		{
			regionName = itemSlotName;
		}

		spAtlasRegion* region = spAtlas_findRegion(animation->getAtlas(), regionName);
		if(region)
		{
			switch (attach->type) 
			{
			case SP_ATTACHMENT_REGION:
			{
				/*
				spRegionAttachment* attachment = SUB_CAST(spRegionAttachment, attach);
				attachment = spRegionAttachment_create(regionName);
				attachment->rendererObject = region;
				spRegionAttachment_setUVs(attachment, region->u, region->v, region->u2, region->v2, region->rotate);
				attachment->regionOffsetX = region->offsetX;
				attachment->regionOffsetY = region->offsetY;
				attachment->regionWidth = region->width;
				attachment->regionHeight = region->height;
				attachment->regionOriginalWidth = region->originalWidth;
				attachment->regionOriginalHeight = region->originalHeight;
				spRegionAttachment_updateOffset( attachment );
				*/
			}
			break;
			case SP_ATTACHMENT_MESH: 
			case SP_ATTACHMENT_LINKED_MESH:
				{
					spMeshAttachment* mesh = SUB_CAST(spMeshAttachment, attach);
					FREE(mesh->path);
					MALLOC_STR(mesh->path, region->name);
					mesh->regionU = region->u;
					mesh->regionV = region->v;
					mesh->regionU2 = region->u2;
					mesh->regionV2 = region->v2;
					mesh->regionRotate = region->rotate;
					mesh->regionOffsetX = region->offsetX;
					mesh->regionOffsetY = region->offsetY;

					mesh->regionWidth = region->width;
					mesh->regionHeight = region->height;
					mesh->regionOriginalWidth = region->originalWidth;
					mesh->regionOriginalHeight = region->originalHeight;

					/*
					auto polygon = frame->getPolygonInfo();
					mesh->triangles = polygon.triangles.indices;
					mesh->trianglesCount = polygon.triangles.indexCount;
					mesh->super.worldVerticesLength = polygon.triangles.vertCount << 1;
					*/
			
					
					delete (spine::AttachmentVertices*)mesh->rendererObject;
				
					spMeshAttachment_updateUVsCustom( mesh );
					//spMeshAttachment_updateUVsCustom2( mesh, frame );
					
					spine::AttachmentVertices* attachmentVertices = new spine::AttachmentVertices((Texture2D*)region->page->rendererObject,
						mesh->super.worldVerticesLength >> 1, mesh->triangles, mesh->trianglesCount);

					//////////////

					float width = mesh->regionU2 - mesh->regionU, height = mesh->regionV2 - mesh->regionV;

					float regionScaleX = (float)mesh->regionWidth / (float)mesh->regionOriginalWidth;
					float regionScaleY = (float)mesh->regionHeight / (float)mesh->regionOriginalHeight;

					width  /= regionScaleX;
					height /= regionScaleY;

					float offsetX = mesh->regionOffsetX / (float)mesh->regionOriginalWidth;
					float offsetY = ( mesh->regionOriginalHeight - mesh->regionOffsetY ) / (float)mesh->regionOriginalHeight;

					//////////////

					V3F_C4B_T2F* vertices = attachmentVertices->_triangles->verts;
					for (int i = 0, ii = 0, nn = mesh->super.worldVerticesLength; ii < nn; ++i, ii += 2)
					{
						vertices[i].texCoords.u = mesh->uvs[ii];
						vertices[i].texCoords.v = mesh->uvs[ii + 1];

						 Vec2 pt;

						 pt.x = mesh->regionUVs[i] * region->originalWidth;
						 pt.y = ( 1 - mesh->regionUVs[i + 1] ) * region->originalHeight;

						points.push_back( pt );
					}

					mesh->rendererObject = attachmentVertices;
				}
				break;
			}
		}
	}
	else
	{
		//log("SpineAnimationHelper::setItem -> Don't found skin whith name = %s", skinName);
		//log("SpineAnimationHelper::setItem -> Don't found attachment for slot = %s", itemSlotName);
	}
}

void SpineHelper::spMeshAttachment_updateUVsCustom2( spMeshAttachment* self, SpriteFrame* frame )
{
	int i;
	float width = self->regionU2 - self->regionU, height = self->regionV2 - self->regionV;

	float regionScaleX = (float)self->regionWidth / (float)self->regionOriginalWidth;
	float regionScaleY = (float)self->regionHeight / (float)self->regionOriginalHeight;

	width  /= regionScaleX;
	height /= regionScaleY;

	float offsetX = self->regionOffsetX / (float)self->regionOriginalWidth;
	float offsetY = ( self->regionOriginalHeight - self->regionOffsetY ) / (float)self->regionOriginalHeight;


	const cocos2d::PolygonInfo& polygon = frame->getPolygonInfo();
	self->triangles = polygon.triangles.indices;
	self->trianglesCount = polygon.triangles.indexCount;
	self->super.worldVerticesLength = polygon.triangles.vertCount;

	std::vector< float > custRegions;

	for (i = 0; i < polygon.triangles.vertCount >> 1; i ++ ) 
	{
		auto& vec =  polygon.triangles.verts[ i ].vertices;
		log( "polygon i[%d] = [%.2f, %.2f ]", i , vec.x, vec.y );
	}

	int verticesLength = SUPER(self)->worldVerticesLength;
	FREE(self->uvs);
	self->uvs = MALLOC(float, verticesLength);
	if (self->regionRotate) {
		for (i = 0; i < verticesLength; i += 2) {
			self->uvs[i] = self->regionU + self->regionUVs[i + 1] * width;
			self->uvs[i + 1] = self->regionV + height - self->regionUVs[i] * height;
		} 
	} else {
		int j = 0; 
		for (i = 0; i < verticesLength; i += 2) {

			/*
			float x = self->regionU + ( self->regionUVs[i] - offsetX ) * width;
			float y = self->regionV + ( self->regionUVs[i+1] - offsetY ) * height;
			*/

			auto& vec =  polygon.triangles.verts[ j ].vertices;
			auto& tex =  polygon.triangles.verts[ j ].texCoords;

			float custRegionU = vec.x / (float)self->regionOriginalWidth;
			float custRegionV = ( self->regionOriginalHeight - vec.y ) / (float)self->regionOriginalHeight;

		//	float custRegionU = tex.u;
		//	float custRegionV = tex.v;

			float x = self->regionU + ( custRegionU ) * width;
			float y = self->regionV + ( custRegionV ) * height;

			self->uvs[i]			= x;
			self->uvs[i + 1]		= y;
			log( "custRegion[ %.4f, %.4f ] uvs[ %d ]=[ %.4f, %.4f ]",custRegionU, custRegionV, i, self->uvs[i], self->uvs[i+1] );

			j++;
		}
	}
}

void SpineHelper::spMeshAttachment_updateUVsCustom( spMeshAttachment* self )
{
	int i;
	float width = self->regionU2 - self->regionU, height = self->regionV2 - self->regionV;

	float regionScaleX = (float)self->regionWidth / (float)self->regionOriginalWidth;
	float regionScaleY = (float)self->regionHeight / (float)self->regionOriginalHeight;

	width  /= regionScaleX;
	height /= regionScaleY;

	float offsetX = self->regionOffsetX / (float)self->regionOriginalWidth;
	float offsetY = ( self->regionOriginalHeight - self->regionOffsetY ) / (float)self->regionOriginalHeight;

	float maxY = offsetY + (self->regionHeight / (float)self->regionOriginalHeight );
	maxY = 0.639f;
	float maxY2 = 1 - ( self->regionOffsetY - self->regionHeight ) / (float)self->regionOriginalHeight;

	
	int verticesLength = SUPER(self)->worldVerticesLength;
	FREE(self->uvs);
	self->uvs = MALLOC(float, verticesLength);
	if (self->regionRotate) {
		for (i = 0; i < verticesLength; i += 2) {
			self->uvs[i] = self->regionU + self->regionUVs[i + 1] * width;
			self->uvs[i + 1] = self->regionV + height - self->regionUVs[i] * height;
		} 
	} else {
		for (i = 0; i < verticesLength; i += 2) {

			/*
			float x = self->regionU + ( self->regionUVs[i] - offsetX ) * width;
			float y = self->regionV + ( self->regionUVs[i+1] - offsetY ) * height;
		
			self->uvs[i]			= x;
			self->uvs[i + 1]		= y;
			*/

			float tempx = self->regionUVs[i];
			float tempy = self->regionUVs[i+1];

			if ( tempy > maxY )
			{
				//tempy = maxY;
			}
			else if ( tempy < offsetY )
			{
				//tempy = offsetY;
			}

			tempx -= offsetX;
			tempy -= offsetY;

			float x = self->regionU + ( tempx) * width;
			float y = self->regionV + ( tempy ) * height;
			self->uvs[i]			= x;
			self->uvs[i + 1]		= y;

			float max = 0.71f;

			if ( y > max )
			{
				//self->uvs[i]	 = 1.0f;
				//self->uvs[i + 1]	 = max;
			}
			//log( "temp[ %d ]=[ %.4f, %.4f ]", i, tempx, tempy );
			log( "uvs[ %d ]=[ %.4f, %.4f ]", i, self->uvs[i], self->uvs[i+1] );
		}
	}
}

std::vector<std::string> SpineHelper::getAtlasTexturesNames( const std::string& aAtlasPath, bool aIsFullPath )
{
	std::vector<std::string> result;

	std::string atlasPath = aAtlasPath;

	if ( !aIsFullPath )
	{
		atlasPath = GET_RESOURCE_PATH( aAtlasPath );
	}

	int length = 0;

    const char* atlasFile = _spUtil_readFile( atlasPath.c_str(), &length );
	const char* atlasFileBegin = atlasFile;
	const char* atlasFileEnd = atlasFileBegin + length;

	Str currentFileLine;
	bool isNextLineTextureName = false;

	while ( readLine(&atlasFileBegin, atlasFileEnd, &currentFileLine) )
	{
		if (currentFileLine.end - currentFileLine.begin == 0)
		{
			isNextLineTextureName = true;
		}
		else if (isNextLineTextureName)
		{
			int nameLength = currentFileLine.end - currentFileLine.begin;

			const char* textureName = mallocString( currentFileLine.begin, nameLength );

			result.push_back( textureName );

			isNextLineTextureName = false;

			FREE(textureName);
		}
	}
    
    FREE(atlasFile);

	return result;
}
