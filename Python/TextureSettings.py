import unreal

aregistry = None
aregistry = unreal.AssetRegistryHelpers.get_asset_registry()

# Test if AssetRegistry was Found
#if aregistry is not None:
#    print "Got AssetRegistry"
    
# Find Assets in a given Path
assetlist = aregistry.get_assets_by_path("/Game/Sprites/UI/Icons", True, True)

# Detect if our AssetPath was valid / Assets were found
#print len(uitextures)

for textureasset in assetlist:
    #print textureasset
    texture = textureasset.get_asset()
    
    #print texture.lod_group
    print texture.compression_settings
    
    # These are equivalent
    #print texture.mip_gen_settings
    #print texture.get_editor_property("mip_gen_settings")
    
    
    #if texture.never_stream == False:
    #    texture.never_stream = True;
    #    print "We did it"
    
    # Set our LOD Group to  TEXTUREGROUP_UI(15)
    texturelodgroup = unreal.TextureGroup.cast(16)
    if texture.get_editor_property("lod_group") != texturelodgroup:
        texture.set_editor_property("lod_group", texturelodgroup)
    
    # Set our CompressionSetting to UserInterface2D (7)
    texturecompressionsetting = unreal.TextureCompressionSettings.cast(7)
    if texture.get_editor_property("compression_settings") != texturecompressionsetting:
        texture.set_editor_property("compression_settings", texturecompressionsetting)
        count = count + 1
    
    # Set our MipGenSetting to NoMipMaps (13)
    texturemipsetting = unreal.TextureMipGenSettings.cast(13)
    if texture.get_editor_property("mip_gen_settings") != texturemipsetting:
        texture.set_editor_property("mip_gen_settings", texturemipsetting)
    
    # Set our NeverStream property to True
    if texture.get_editor_property("never_stream") == False:
        texture.set_editor_property("never_stream", True)
    
    # Save the asset (True == only_if_is_dirty)
    unreal.EditorAssetLibrary.save_asset(textureasset.get_full_name(), True)

#end For-loop