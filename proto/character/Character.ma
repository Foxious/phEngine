//Maya ASCII 2011 scene
//Name: Character.ma
//Last modified: Tue, Jan 01, 2013 04:56:52 PM
//Codeset: 1252
requires maya "2011";
requires "stereoCamera" "10.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2011";
fileInfo "version" "2011";
fileInfo "cutIdentifier" "201003190014-771504";
fileInfo "osv" "Microsoft Windows 7 Business Edition, 64-bit Windows 7 Service Pack 1 (Build 7601)\n";
createNode transform -s -n "persp";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 7.3604851968878462 6.5689975770283784 8.83432872048812 ;
	setAttr ".r" -type "double3" -29.738352729602362 39.799999999999947 -2.0699094694800809e-015 ;
createNode camera -s -n "perspShape" -p "persp";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 13.2428786690149;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
createNode transform -s -n "top";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 100.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
createNode transform -s -n "front";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 10.028571428571425 7.542857142857148 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
createNode transform -s -n "side";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 100.1 9.1110723017813449 0.98498078938176725 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 25.029802637175496;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
createNode transform -n "front1";
	setAttr ".t" -type "double3" 16 16 100 ;
	setAttr -l on ".tx";
	setAttr -l on ".ty";
	setAttr -l on ".tz";
	setAttr ".rp" -type "double3" 1.7763568394002505e-015 0 0 ;
	setAttr ".rpt" -type "double3" 1.0756039724649316e-015 1.0158760049444129e-015 -1.7135948430967392e-016 ;
createNode camera -n "frontShape2" -p "front1";
	setAttr -k off ".v";
	setAttr ".ovr" 1.3;
	setAttr -l on ".sa";
	setAttr ".coi" 100.1;
	setAttr -l on ".ow" 9.1065375889569253;
	setAttr ".imn" -type "string" "front1";
	setAttr ".den" -type "string" "front1_depth";
	setAttr ".man" -type "string" "front1_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".dr" yes;
	setAttr ".o" yes;
createNode transform -n "pPlane3";
	setAttr ".t" -type "double3" 15.056338527601795 12.641128377833239 0 ;
	setAttr ".r" -type "double3" 90.000000000000014 3.1805546814635168e-015 -90.000000000000043 ;
	setAttr ".s" -type "double3" 1.0867781658914464 1.0867781658914464 0.85913143012069904 ;
createNode transform -n "transform4" -p "pPlane3";
	setAttr ".v" no;
createNode mesh -n "pPlaneShape3" -p "transform4";
	addAttr -ci true -sn "mso" -ln "miShadingSamplesOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "msh" -ln "miShadingSamples" -min 0 -smx 8 -at "float";
	addAttr -ci true -sn "mdo" -ln "miMaxDisplaceOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "mmd" -ln "miMaxDisplace" -min 0 -smx 1 -at "float";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 1 0 0 1 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -1 -2.220446e-016 1 1 -2.220446e-016 1 -1 
		2.220446e-016 -1 1 2.220446e-016 -1;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 0 2 -4 -2 
		mu 0 4 0 1 3 2 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "pPlane5";
	setAttr ".t" -type "double3" 13.260646157848775 15.521012367059772 0 ;
	setAttr ".r" -type "double3" 89.999999999999986 0 0 ;
	setAttr ".s" -type "double3" 0.77847757270262441 2.0690347001304854 1.5666674867152153 ;
createNode transform -n "transform3" -p "pPlane5";
	setAttr ".v" no;
createNode mesh -n "pPlaneShape5" -p "transform3";
	addAttr -ci true -sn "mso" -ln "miShadingSamplesOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "msh" -ln "miShadingSamples" -min 0 -smx 8 -at "float";
	addAttr -ci true -sn "mdo" -ln "miMaxDisplaceOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "mmd" -ln "miMaxDisplace" -min 0 -smx 1 -at "float";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 1 0 0 1 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -1 -2.220446e-016 1 1 -2.220446e-016 1 -1 
		2.220446e-016 -1 1 2.220446e-016 -1;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 0 2 -4 -2 
		mu 0 4 0 1 3 2 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface1";
	setAttr ".t" -type "double3" 0 0.085714285714286298 0 ;
createNode transform -n "Body" -p "polySurface1";
	setAttr ".rp" -type "double3" 16.174411773681641 13.759201671133592 0 ;
	setAttr ".sp" -type "double3" 16.174411773681641 13.759201671133592 0 ;
createNode mesh -n "BodyShape" -p "Body";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.32306665 0.57655233 
		0.32306665 0.0049768537 0.97959852 0.0049768537 0.97959852 0.57655233;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  14.105377 17.149595 -8.0398154e-016 14.105377 
		13.011525 -1.0336905e-015 18.243446 17.149595 1.0336905e-015 18.243446 13.011525 
		8.0398154e-016;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 0 2 -4 -2 
		mu 0 4 0 1 2 3 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode transform -n "Head" -p "polySurface1";
	setAttr ".t" -type "double3" -1.0670349924116778 -0.53749532344991735 -1 ;
	setAttr ".rp" -type "double3" 16.140530308735933 17.45222920267004 0 ;
	setAttr ".sp" -type "double3" 16.140530308735933 17.45222920267004 0 ;
createNode mesh -n "HeadShape" -p "Head";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.29619423 0.99224371 
		0.29619423 0.59936267 0.74747181 0.59936267 0.74747181 0.99224371;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  14.752229 19.958603 -5.5262902e-016 14.752229 
		17.114239 -7.1052305e-016 17.596594 19.958603 7.1052305e-016 17.596594 17.114239 
		5.5262902e-016;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 0 2 -4 -2 
		mu 0 4 0 1 2 3 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode transform -n "LegL" -p "polySurface1";
	setAttr ".rp" -type "double3" 14.954695345916056 13.522034230861294 0 ;
	setAttr ".sp" -type "double3" 14.954695345916056 13.522034230861294 0 ;
createNode mesh -n "LegLShape" -p "LegL";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.023954049 0.35608691 
		0.023954049 0.055861976 0.29400966 0.055861976 0.29400966 0.35608691;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  14.197206 13.727907 -3.7175043e-016 14.197206 
		11.55435 -4.9240704e-016 15.91547 13.727907 4.9240704e-016 15.91547 11.55435 3.7175043e-016;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 0 2 -4 -2 
		mu 0 4 0 1 2 3 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode transform -n "ArmL" -p "polySurface1";
	setAttr ".rp" -type "double3" 13.27104790486838 16.338308916440408 0 ;
	setAttr ".sp" -type "double3" 13.27104790486838 16.338308916440408 0 ;
createNode mesh -n "ArmLShape" -p "ArmL";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.019239806 0.45439833 
		0.26542145 0.45439833 0.26542145 0.8871935 0.019239806 0.8871935;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  12.482168 13.954345 -1.1154797e-016 14.039124 
		13.954345 -1.1154797e-016 12.482168 17.087679 1.1154797e-016 14.039124 17.087679 
		1.1154797e-016;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 0 2 -4 -2 
		mu 0 4 0 1 2 3 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode transform -n "ArmR" -p "polySurface1";
	setAttr ".t" -type "double3" -2.7650138504856265 -0.19801440872418041 -2 ;
	setAttr ".r" -type "double3" 0 0 46.831210418539655 ;
	setAttr -av ".rz";
	setAttr ".rp" -type "double3" 18.851009411874255 16.334155145320526 0 ;
	setAttr ".sp" -type "double3" 18.851009411874255 16.334155145320526 0 ;
createNode mesh -n "ArmRShape" -p "ArmR";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.019239783 0.45430249 
		0.019239783 0.88709772 0.26542145 0.88709772 0.26542145 0.45430249;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  19.798891 13.886582 -1.1154797e-016 18.241938 
		13.886582 -1.1154797e-016 19.798891 17.019917 1.1154797e-016 18.241938 17.019917 
		1.1154797e-016;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 1 3 -3 -1 
		mu 0 4 0 1 2 3 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode transform -n "LegR" -p "polySurface1";
	setAttr ".rp" -type "double3" 17.021436335601116 13.623677195186939 0 ;
	setAttr ".sp" -type "double3" 17.021436335601116 13.623677195186939 0 ;
createNode mesh -n "LegRShape" -p "LegR";
	addAttr -ci true -sn "mso" -ln "miShadingSamplesOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "msh" -ln "miShadingSamples" -min 0 -smx 8 -at "float";
	addAttr -ci true -sn "mdo" -ln "miMaxDisplaceOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "mmd" -ln "miMaxDisplace" -min 0 -smx 1 -at "float";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.29314619 0.055861976 
		0.023954034 0.055861976 0.023954034 0.35608691 0.29314619 0.35608691;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  16.263948 11.55435 -4.9240704e-016 16.263948 
		13.727907 -3.7175043e-016 17.98221 11.55435 3.7175043e-016 17.98221 13.727907 4.9240704e-016;
	setAttr -s 4 ".ed[0:3]"  0 1 0 0 2 0 
		1 3 0 2 3 0;
	setAttr ".fc[0]" -type "polyFaces" 
		f 4 1 3 -3 -1 
		mu 0 4 0 1 2 3 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
createNode lightLinker -s -n "lightLinker1";
	setAttr -s 3 ".lnk";
	setAttr -s 3 ".slnk";
createNode displayLayerManager -n "layerManager";
createNode displayLayer -n "defaultLayer";
createNode renderLayerManager -n "renderLayerManager";
createNode renderLayer -n "defaultRenderLayer";
	setAttr ".g" yes;
createNode script -n "uiConfigurationScriptNode";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n"
		+ "                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n"
		+ "                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n"
		+ "            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n"
		+ "            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n"
		+ "                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n"
		+ "                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n"
		+ "                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n"
		+ "            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n"
		+ "            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front1\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 1\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n"
		+ "                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"perPolygonSort\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n"
		+ "                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front1\" \n            -useInteractiveMode 0\n"
		+ "            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n"
		+ "            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"perPolygonSort\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n"
		+ "            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front1\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n"
		+ "                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 1\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"hwRender_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"perPolygonSort\" \n"
		+ "                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n"
		+ "                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front1\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n"
		+ "            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"hwRender_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"perPolygonSort\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n"
		+ "            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n"
		+ "\t\tmodelPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n                -showShapes 0\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 1\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n                -showContainerContents 1\n                -ignoreDagHierarchy 0\n                -expandConnections 0\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 1\n"
		+ "                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n"
		+ "                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n"
		+ "            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"graphEditor\" -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n"
		+ "                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n"
		+ "                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -clipTime \"on\" \n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n"
		+ "                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n"
		+ "                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n"
		+ "                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -clipTime \"on\" \n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dopeSheetPanel\" -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n"
		+ "                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n"
		+ "                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n"
		+ "                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n"
		+ "                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n"
		+ "            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"clipEditorPanel\" -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n"
		+ "                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n"
		+ "\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"sequenceEditorPanel\" -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n"
		+ "                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n"
		+ "                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n"
		+ "                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperShadePanel\" -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"visorPanel\" -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Texture Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"polyTexturePlacementPanel\" -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"renderWindowPanel\" -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"blendShapePanel\" (localizedPanelLabel(\"Blend Shape\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tblendShapePanel -unParent -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels ;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tblendShapePanel -edit -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynRelEdPanel\" -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"relationshipPanel\" -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"referenceEditorPanel\" -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"componentEditorPanel\" -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynPaintScriptedPanelType\" -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"scriptEditorPanel\" -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"Stereo\" -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels `;\nstring $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n"
		+ "                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n"
		+ "                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n"
		+ "                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                $editorName;\nstereoCameraView -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\nstring $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n"
		+ "                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n"
		+ "                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n"
		+ "                -textures 1\n                -strokes 1\n                -shadows 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                $editorName;\nstereoCameraView -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"vertical2\\\" -ps 1 16 100 -ps 2 84 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Outliner\")) \n\t\t\t\t\t\"outlinerPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\\\"Outliner\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\noutlinerEditor -e \\n    -showShapes 0\\n    -showAttributes 0\\n    -showConnected 0\\n    -showAnimCurvesOnly 0\\n    -showMuteInfo 0\\n    -organizeByLayer 1\\n    -showAnimLayerWeight 1\\n    -autoExpandLayers 1\\n    -autoExpand 0\\n    -showDagOnly 1\\n    -showAssets 1\\n    -showContainedOnly 1\\n    -showPublishedAsConnected 0\\n    -showContainerContents 1\\n    -ignoreDagHierarchy 0\\n    -expandConnections 0\\n    -showUpstreamCurves 1\\n    -showUnitlessCurves 1\\n    -showCompounds 1\\n    -showLeafs 1\\n    -showNumericAttrsOnly 0\\n    -highlightActive 1\\n    -autoSelectNewObjects 0\\n    -doNotSelectNewObjects 0\\n    -dropIsParent 1\\n    -transmitFilters 0\\n    -setFilter \\\"defaultSetFilter\\\" \\n    -showSetMembers 1\\n    -allowMultiSelection 1\\n    -alwaysToggleSelect 0\\n    -directSelect 0\\n    -displayMode \\\"DAG\\\" \\n    -expandObjects 0\\n    -setsIgnoreFilters 1\\n    -containersIgnoreFilters 0\\n    -editAttrName 0\\n    -showAttrValues 0\\n    -highlightSecondary 0\\n    -showUVAttrsOnly 0\\n    -showTextureNodesOnly 0\\n    -attrAlphaOrder \\\"default\\\" \\n    -animLayerFilterOptions \\\"allAffecting\\\" \\n    -sortOrder \\\"none\\\" \\n    -longNames 0\\n    -niceNames 1\\n    -showNamespace 1\\n    -showPinIcons 0\\n    $editorName\"\n"
		+ "\t\t\t\t\t\"outlinerPanel -edit -l (localizedPanelLabel(\\\"Outliner\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\noutlinerEditor -e \\n    -showShapes 0\\n    -showAttributes 0\\n    -showConnected 0\\n    -showAnimCurvesOnly 0\\n    -showMuteInfo 0\\n    -organizeByLayer 1\\n    -showAnimLayerWeight 1\\n    -autoExpandLayers 1\\n    -autoExpand 0\\n    -showDagOnly 1\\n    -showAssets 1\\n    -showContainedOnly 1\\n    -showPublishedAsConnected 0\\n    -showContainerContents 1\\n    -ignoreDagHierarchy 0\\n    -expandConnections 0\\n    -showUpstreamCurves 1\\n    -showUnitlessCurves 1\\n    -showCompounds 1\\n    -showLeafs 1\\n    -showNumericAttrsOnly 0\\n    -highlightActive 1\\n    -autoSelectNewObjects 0\\n    -doNotSelectNewObjects 0\\n    -dropIsParent 1\\n    -transmitFilters 0\\n    -setFilter \\\"defaultSetFilter\\\" \\n    -showSetMembers 1\\n    -allowMultiSelection 1\\n    -alwaysToggleSelect 0\\n    -directSelect 0\\n    -displayMode \\\"DAG\\\" \\n    -expandObjects 0\\n    -setsIgnoreFilters 1\\n    -containersIgnoreFilters 0\\n    -editAttrName 0\\n    -showAttrValues 0\\n    -highlightSecondary 0\\n    -showUVAttrsOnly 0\\n    -showTextureNodesOnly 0\\n    -attrAlphaOrder \\\"default\\\" \\n    -animLayerFilterOptions \\\"allAffecting\\\" \\n    -sortOrder \\\"none\\\" \\n    -longNames 0\\n    -niceNames 1\\n    -showNamespace 1\\n    -showPinIcons 0\\n    $editorName\"\n"
		+ "\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Front View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Front View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -camera \\\"front1\\\" \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"perPolygonSort\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Front View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -camera \\\"front1\\\" \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"perPolygonSort\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 16 -ast 1 -aet 16 ";
	setAttr ".st" 6;
createNode psdFileTex -n "psdFileTex1";
	setAttr ".ftn" -type "string" "H:/Projects/Foxious/phEngine/proto/character//UV.tif";
createNode place2dTexture -n "place2dTexture1";
createNode animCurveTL -n "polySurface2_translateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 0 2 0 3 -0.50821482162821141 4 -0.84702470271368391 
		5 -0.74538173838804234 6 -0.64373877406239721 7 -0.50821482162820963 8 -0.50821482162820963 
		9 -0.50821482162820963 10 0.043417477502359247 11 0.072362462503935632 12 0 13 0.56442720753070219 
		14 0.54995471502991222 15 -0.3039223425165325 16 -0.072362462503932079;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  1 1 1 1 1 0.13272352516651154 1;
	setAttr -s 16 ".kiy[9:15]"  0 0 0 0 0 -0.99115312099456787 0;
	setAttr -s 16 ".kox[15]"  1;
	setAttr -s 16 ".koy[15]"  0;
createNode animCurveTL -n "polySurface2_translateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 0 2 -0.27104790486837871 3 0.64373877406240254 
		4 1.4907634767760864 5 0.40657185730256984 6 -1.016429643256421 7 -0.16940494054273536 
		8 -0.16940494054273536 9 -0.16940494054273536 10 0.057889970003150992 11 0.26050486501417502 
		12 0 13 -0.49206474502676834 14 -0.75256961004093803 15 0.11577994000630021 16 0.057889970003149216;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.36146560311317444 0.96770346164703369 
		0.15193961560726166 0.15193961560726166 0.13582588732242584 0.10228309035301208 0.15193961560726166;
	setAttr -s 16 ".kiy[9:15]"  0.93238550424575806 -0.25209146738052368 
		-0.98838979005813599 -0.98838979005813599 0.99073272943496704 0.9947553277015686 
		-0.98838979005813599;
	setAttr -s 16 ".kox[15]"  0.15193960070610046;
	setAttr -s 16 ".koy[15]"  -0.98838973045349121;
createNode animCurveTL -n "polySurface2_translateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTL -n "polySurface3_translateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -0.27104790486837516 2 -0.067761976217099118 
		3 -0.59306126210400478 4 -1.1924134164415978 5 -0.88929370244133921 6 -0.68937549081078053 
		7 0.21348311924706209 8 -0.91640600707124564 9 -0.36874356960856147 10 0.3512692726654727 
		11 -0.98020003740695572 12 -0.27104790486837516 13 0.53941167517571742 14 1.2775087927158779 
		15 -1.6604071849439439 16 -1.0670349924116778;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.98145020008087158 0.40497946739196777 
		0.20079149305820465 0.20079149305820465 0.037854745984077454 0.035521101206541061 
		0.20079149305820465;
	setAttr -s 16 ".kiy[9:15]"  -0.19171705842018127 -0.91432583332061768 
		0.97963404655456543 0.97963404655456543 -0.99928325414657593 -0.99936890602111816 
		0.97963404655456543;
	setAttr -s 16 ".kox[15]"  0.20079147815704346;
	setAttr -s 16 ".koy[15]"  0.97963398694992065;
createNode animCurveTL -n "polySurface3_translateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -0.60985778595385653 2 -0.98254865514788037 
		3 0.033305107290839686 4 0.77983837435279391 5 -0.126231351326755 6 -1.7218344807856187 
		7 -0.80237087615315339 8 -0.76248670325838042 9 -0.71421451874450703 10 -0.47960535344677524 
		11 -0.32040793593812111 12 -0.60985778595385653 13 -1.0729775459790432 14 -1.3479549034940099 
		15 -0.52302283094912738 16 -0.53749532344991735;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.38975149393081665 0.78792321681976318 
		0.11110733449459076 0.11110733449459076 0.14981740713119507 1 0.11110733449459076;
	setAttr -s 16 ".kiy[9:15]"  0.92092007398605347 -0.61577355861663818 
		-0.99380844831466675 -0.99380844831466675 0.98871374130249023 0 -0.99380844831466675;
	setAttr -s 16 ".kox[15]"  0.11110732704401016;
	setAttr -s 16 ".koy[15]"  -0.99380838871002197;
createNode animCurveTL -n "polySurface4_translateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 0.47433383351966185 2 -0.16307025154793919 
		3 -0.29229530419068972 4 -0.57195701959514089 5 -0.50821482162821141 6 -0.22187113086616606 
		7 0.2710479048683716 8 -0.16940494054274424 9 -0.16940494054274424 10 0.51775131102201755 
		11 0.26448261309550292 12 0.47433383351966185 13 0.56116878852438745 14 0.4309163560173026 
		15 -0.032203404007891123 16 0.19935647600470574;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.35857954621315002 1 0.065230093896389008 
		0.065230093896389008 0.1390753835439682 0.33861806988716125 0.065230093896389008;
	setAttr -s 16 ".kiy[9:15]"  0.93349915742874146 0 -0.99787026643753052 
		-0.99787026643753052 -0.99028182029724121 -0.94092392921447754 -0.99787026643753052;
	setAttr -s 16 ".kox[15]"  0.065230093896389008;
	setAttr -s 16 ".koy[15]"  -0.99787026643753052;
createNode animCurveTL -n "polySurface4_translateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 0 2 -0.050677511958392429 3 1.1910028701208049 
		4 1.9874932176895364 5 1.3552395243419006 6 -0.0087169532512216819 7 0.067761976217099118 
		8 3.5527136788005009e-015 9 3.5527136788005009e-015 10 0.086834955004727377 11 -0.13025243250707952 
		12 0 13 -0.46311976002519373 14 -0.43417477502361912 15 0.014472492500788192 16 -0.028944985001574608;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.78792321681976318 0.29718390107154846 
		0.63509172201156616 0.63509172201156616 1 1 0.63509172201156616;
	setAttr -s 16 ".kiy[9:15]"  -0.61577343940734863 0.95482027530670166 
		-0.77243679761886597 -0.77243679761886597 0 0 -0.77243679761886597;
	setAttr -s 16 ".kox[15]"  0.63509172201156616;
	setAttr -s 16 ".koy[15]"  -0.77243679761886597;
createNode animCurveTL -n "polySurface4_translateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 -1 2 -1 3 -1 4 -1 5 -1 6 -1 7 -1 8 -1 
		9 -1 12 -1 13 -1 16 -1;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTL -n "polySurface5_translateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 1.5585254529931802 2 1.7099821080506548 
		3 1.3537998222976242 4 0.74538173838804411 5 1.1180726075820697 6 1.4230015005589962 
		7 1.8481585600764436 8 1.1180726075820697 9 1.7543279595136969 10 2.1229526605238878 
		11 1.5440529604923956 12 1.5585254529931802 13 2.6150174055506561 14 3.1794446130813618 
		15 0.357308575427842 16 1.2401306179758649;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no yes yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.90147548913955688 0.60896754264831543 
		0.26525169610977173 0.26525169610977173 0.036885447800159454 0.042930923402309418 
		0.26525169610977173;
	setAttr -s 16 ".kiy[9:15]"  -0.43283024430274963 -0.79319512844085693 
		0.96417921781539917 0.96417921781539917 -0.99931949377059937 -0.99907797574996948 
		0.96417921781539917;
	setAttr -s 16 ".kox[15]"  0.26525169610977173;
	setAttr -s 16 ".koy[15]"  0.96417921781539917;
createNode animCurveTL -n "polySurface5_translateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -0.30492889297692471 2 -0.49257005941378296 
		3 0.30406507175036168 4 1.558525452993182 5 0.27104790486838581 6 -0.98254865514787326 
		7 -0.2617553037609337 8 -0.60985778595385121 9 -0.034785577596876394 10 -0.0010065504603886666 
		11 -0.0010065504603851139 12 -0.30492889297692471 13 -0.72463117549975742 14 -1.071970995518658 
		15 -0.17467646046984342 16 -0.66674120549660465;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no yes yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  1 1 0.21677492558956146 0.21677492558956146 
		0.14981740713119507 0.20142963528633118 0.21677492558956146;
	setAttr -s 16 ".kiy[9:15]"  0 0 -0.97622162103652954 -0.97622162103652954 
		0.98871374130249023 0.97950303554534912 -0.97622162103652954;
	setAttr -s 16 ".kox[15]"  0.21677492558956146;
	setAttr -s 16 ".koy[15]"  -0.97622162103652954;
createNode animCurveTL -n "polySurface6_translateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -1.6940494054273678 2 -1.4901875959583784 
		3 -2.0667402746213881 4 -2.1345022508384819 5 -1.9989782984042908 6 -1.8634543459701067 
		7 -1.5483282623974031 8 -2.270026203272673 9 -1.917400773638084 10 -1.5493244804194894 
		11 -1.9400817779407475 12 -1.6940494054273678 13 -1.3756545704100454 14 -0.42047006535808507 
		15 -3.0978811780037354 16 -2.7650138504856265;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.97604250907897949 0.56084716320037842 
		0.20024706423282623 0.20024706423282623 0.048330415040254593 0.035521101206541061 
		0.20024706423282623;
	setAttr -s 16 ".kiy[9:15]"  -0.21758031845092773 -0.8279193639755249 
		0.97974544763565063 0.97974544763565063 -0.99883139133453369 -0.99936890602111816 
		0.97974544763565063;
	setAttr -s 16 ".kox[15]"  0.20024706423282623;
	setAttr -s 16 ".koy[15]"  0.97974544763565063;
createNode animCurveTL -n "polySurface6_translateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -0.067761976217095565 2 -0.54238375014561058 
		3 0.37269086919402739 4 1.2197155719077077 5 0.13552395243419824 6 -1.3891205124504378 
		7 -0.87342226869145634 8 -0.47433383351965652 9 -0.55229300033252748 10 -0.29932185622968888 
		11 0.35194030630573181 12 -0.067761976217095565 13 -0.97952900376669128 14 -1.4281762712911004 
		15 -0.038816991215526286 16 -0.19801440872418041;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.26165363192558289 0.91727375984191895 
		0.087452858686447144 0.087452858686447144 0.088239811360836029 0.067586891353130341 
		0.087452858686447144;
	setAttr -s 16 ".kiy[9:15]"  0.96516185998916626 -0.39825716614723206 
		-0.99616867303848267 -0.99616867303848267 0.99609923362731934 0.99771338701248169 
		-0.99616867303848267;
	setAttr -s 16 ".kox[15]"  0.087452858686447144;
	setAttr -s 16 ".koy[15]"  -0.99616867303848267;
createNode animCurveTL -n "polySurface7_translateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -0.37269086919402383 2 -0.35704610697959538 
		3 -1.2145472855860646 4 -1.3753384155927328 5 -0.91478667893078125 6 -1.13994722611816 
		7 -0.74538173838804056 8 -0.90458948833500585 9 -0.67761976217094855 10 -0.66214071920976636 
		11 -0.53188828670268506 12 -0.37269086919402383 13 0.061483905829597063 14 0.17726384583589549 
		15 -0.63319573420819353 16 -0.63319573420819708;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  1 0.94463920593261719 1 1 0.11910543590784073 
		1 1;
	setAttr -s 16 ".kiy[9:15]"  0 -0.32811084389686584 0 0 -0.9928816556930542 
		0 0;
	setAttr -s 16 ".kox[15]"  1;
	setAttr -s 16 ".koy[15]"  0;
createNode animCurveTL -n "polySurface7_translateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -0.033880988108547783 2 -0.018812106711825649 
		3 0.69484738324308992 4 1.9851962015465823 5 1.3891205124504431 6 -0.1832204890918554 
		7 -0.13552395243418935 8 -0.12022816654052626 9 -0.033880988108547783 10 0.067426459396967786 
		11 0.13978892190090342 12 -0.033880988108547783 13 -0.19307840561720724 14 -0.10624345061248341 
		15 0.3424038169119239 16 -0.062825973110122391;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.69240981340408325 0.58417439460754395 
		1 1 0.1537720113992691 0.88684999942779541 1;
	setAttr -s 16 ".kiy[9:15]"  0.72150444984436035 0.81162822246551514 
		0 0 0.988106369972229 0.46205729246139526 0;
	setAttr -s 16 ".kox[15]"  1;
	setAttr -s 16 ".koy[15]"  0;
createNode animCurveTL -n "polySurface7_translateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 -1 2 -1 3 -1 4 -1 5 -1 6 -1 7 -1 8 -1 
		9 -1 12 -1 13 -1 16 -1;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface2_rotateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface2_rotateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface2_rotateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 6.1178818119802036 2 0 3 0 4 0 5 0 6 
		0 7 -14.811713860583684 8 6.4282855337306133 9 -4.0940084392670162 10 -3.6515208186390113 
		11 15.94664705079159 12 6.1178818119802036 13 0.096922174551958173 14 -18.105311691949257 
		15 24.671803808318561 16 18.507469591770601;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  1 0.96488755941390991 0.36352372169494629 
		0.36352372169494629 0.19072331488132477 0.12931442260742188 0.36352372169494629;
	setAttr -s 16 ".kiy[9:15]"  0 0.26266324520111084 -0.93158495426177979 
		-0.93158495426177979 0.98164385557174683 0.99160361289978027 -0.93158495426177979;
	setAttr -s 16 ".kox[15]"  0.36352372169494629;
	setAttr -s 16 ".koy[15]"  -0.93158495426177979;
createNode animCurveTA -n "polySurface3_rotateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 -0.70494602338002965 
		8 -0.9338844693330729 9 -1.1767917609926024 12 0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface3_rotateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 -0.97385762832541767 
		8 -0.75710651799924156 9 -0.24590521177983274 12 0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface3_rotateZ";
	setAttr ".tan" 10;
	setAttr ".wgt" no;
	setAttr -s 15 ".ktv[0:14]"  1 0 2 -15.938692355725863 3 -17.279999796295524 
		4 -37.205970502365155 5 -11.771434140442135 6 -1.0115797021438104 7 -16.717887203111445 
		8 -11.199750403604249 9 -6.7186132970965824 10 -12.507623566704483 12 0 13 -16.097212686656263 
		14 -13.215949029139503 15 -9.0655361594548935 16 0;
	setAttr -s 15 ".kit[9:14]"  1 1 1 10 10 1;
	setAttr -s 15 ".kot[0:14]"  5 5 5 5 5 5 5 5 
		5 5 5 5 10 10 1;
	setAttr -s 15 ".ktl[0:14]" no no no no no no no no no no no no yes 
		yes yes;
	setAttr -s 15 ".kix[9:14]"  1 0.14812929928302765 0.14812929928302765 
		0.56175535917282104 0.33978453278541565 0.14812929928302765;
	setAttr -s 15 ".kiy[9:14]"  0 -0.98896801471710205 -0.98896801471710205 
		0.82730340957641602 0.94050335884094238 -0.98896801471710205;
	setAttr -s 15 ".kox[14]"  0.14812929928302765;
	setAttr -s 15 ".koy[14]"  -0.98896801471710205;
createNode animCurveTA -n "polySurface4_rotateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0.1532537063556888 5 0.43071391034779244 
		6 0.43071391034778989 7 0.4307139103477885 8 0.430713910347788 9 0.430713910347788 
		12 0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface4_rotateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0.89566250192746577 5 0.80012104688013852 
		6 0.80012104688014174 7 0.80012104688014429 8 0.8001210468801464 9 0.8001210468801464 
		12 0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface4_rotateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 0 2 15.895797693611248 3 12.192384257301077 
		4 -37.038122206405646 5 -18.452892086687907 6 -1.4110559699173193 7 -23.359940933657271 
		8 -9.8194752354034289 9 -9.8194752354034289 10 -2.2327580724752898 11 -6.4624625697921338 
		12 0 13 -40.014458707221813 14 -36.260007158303338 15 12.977542328158574 16 0;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.94340282678604126 1 0.14852021634578705 
		0.14852021634578705 0.089737758040428162 0.13055118918418884 0.14852021634578705;
	setAttr -s 16 ".kiy[9:15]"  0.33164903521537781 0 0.98890936374664307 
		0.98890936374664307 0.99596536159515381 0.99144160747528076 0.98890936374664307;
	setAttr -s 16 ".kox[15]"  0.14852021634578705;
	setAttr -s 16 ".koy[15]"  0.98890936374664307;
createNode animCurveTA -n "polySurface5_rotateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 14 ".ktv[0:13]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 11 
		0 12 0 13 0 14 0 16 0;
	setAttr -s 14 ".kit[0:13]"  10 10 10 10 10 10 10 10 
		10 1 1 1 10 1;
	setAttr -s 14 ".kot[12:13]"  10 1;
	setAttr -s 14 ".ktl[0:13]" no no no no no no no no no no no no yes 
		yes;
	setAttr -s 14 ".kix[9:13]"  1 1 1 1 1;
	setAttr -s 14 ".kiy[9:13]"  0 0 0 0 0;
	setAttr -s 14 ".kox[13]"  1;
	setAttr -s 14 ".koy[13]"  0;
createNode animCurveTA -n "polySurface5_rotateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 14 ".ktv[0:13]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 11 
		0 12 0 13 0 14 0 16 0;
	setAttr -s 14 ".kit[0:13]"  10 10 10 10 10 10 10 10 
		10 1 1 1 10 1;
	setAttr -s 14 ".kot[12:13]"  10 1;
	setAttr -s 14 ".ktl[0:13]" no no no no no no no no no no no no yes 
		yes;
	setAttr -s 14 ".kix[9:13]"  1 1 1 1 1;
	setAttr -s 14 ".kiy[9:13]"  0 0 0 0 0;
	setAttr -s 14 ".kox[13]"  1;
	setAttr -s 14 ".koy[13]"  0;
createNode animCurveTA -n "polySurface5_rotateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 -24.604410477556929 2 -63.789667042028327 
		3 -36.621371324545414 4 -93.828206440687026 5 -135.47642278427438 6 -133.71495497463818 
		7 -57.53236340974388 8 -37.668945690749446 9 -41.269389050777512 10 -43.357959557344728 
		11 -22.278699260726963 12 -24.604410477556929 13 -43.51949178329054 14 10.846639714978966 
		15 -97.147030166133575 16 -46.241878404627393;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  1 0.97705531120300293 0.06081128865480423 
		0.06081128865480423 0.088682703673839569 0.083344921469688416 0.06081128865480423;
	setAttr -s 16 ".kiy[9:15]"  0 0.21298576891422272 -0.99814927577972412 
		-0.99814927577972412 -0.99605995416641235 -0.9965207576751709 -0.99814927577972412;
	setAttr -s 16 ".kox[15]"  0.06081128865480423;
	setAttr -s 16 ".koy[15]"  -0.99814927577972412;
createNode animCurveTA -n "polySurface6_rotateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface6_rotateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface6_rotateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 16 ".ktv[0:15]"  1 18.089048331022468 2 60.355171748114174 
		3 14.152615958307925 4 81.94006480456099 5 132.9052848432068 6 148.86271815070188 
		7 18.660688279142676 8 26.480405032423864 9 17.570859843540411 10 10.223385236651124 
		11 24.014213189330196 12 18.089048331022468 13 15.399583881397485 14 56.316254829181815 
		15 49.106386067722454 16 46.831210418539655;
	setAttr -s 16 ".kit[0:15]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 10 1;
	setAttr -s 16 ".kot[13:15]"  10 10 1;
	setAttr -s 16 ".ktl[0:15]" no no no no no no no no no no no no yes 
		yes yes yes;
	setAttr -s 16 ".kix[9:15]"  0.82894617319107056 0.73698562383651733 
		0.056393276900053024 0.056393276900053024 0.14025221765041351 1 0.056393276900053024;
	setAttr -s 16 ".kiy[9:15]"  0.55932837724685669 0.67590844631195068 
		0.99840867519378662 0.99840867519378662 0.99011582136154175 0 0.99840867519378662;
	setAttr -s 16 ".kox[15]"  0.056393273174762726;
	setAttr -s 16 ".koy[15]"  0.99840861558914185;
createNode animCurveTA -n "polySurface7_rotateX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface7_rotateY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 12 ".ktv[0:11]"  1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 12 
		0 13 0 16 0;
	setAttr -s 12 ".kit[0:11]"  10 10 10 10 10 10 10 10 
		10 1 1 1;
	setAttr -s 12 ".kot[11]"  1;
	setAttr -s 12 ".ktl[0:11]" no no no no no no no no no no no yes;
	setAttr -s 12 ".kix[9:11]"  1 1 1;
	setAttr -s 12 ".kiy[9:11]"  0 0 0;
	setAttr -s 12 ".kox[11]"  1;
	setAttr -s 12 ".koy[11]"  0;
createNode animCurveTA -n "polySurface7_rotateZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 15 ".ktv[0:14]"  1 0 2 -11.411259557933843 3 -11.330324549268488 
		4 33.884689973326687 5 13.890053052699587 6 13.252656039668365 7 11.518607370599836 
		8 15.913880473198624 9 7.2677658784387615 10 6.167326513237521 11 -2.4520240195335359 
		12 0 13 0 15 50.434210492957448 16 12.982480756242101;
	setAttr -s 15 ".kit[0:14]"  10 10 10 10 10 10 10 10 
		10 1 1 1 1 10 1;
	setAttr -s 15 ".kot[13:14]"  10 1;
	setAttr -s 15 ".ktl[0:14]" no no no no no no no no no no no no no yes 
		yes;
	setAttr -s 15 ".kix[9:14]"  1 0.91353249549865723 0.20477449893951416 
		0.20477449893951416 0.48303723335266113 0.20477449893951416;
	setAttr -s 15 ".kiy[9:14]"  0 -0.40676581859588623 -0.9788091778755188 
		-0.9788091778755188 0.87559974193572998 -0.9788091778755188;
	setAttr -s 15 ".kox[14]"  0.20477449893951416;
	setAttr -s 15 ".koy[14]"  -0.9788091778755188;
createNode file -n "file1";
	setAttr ".ftn" -type "string" "H:/Projects/Foxious/phEngine/proto/character//UV.tif";
createNode place2dTexture -n "place2dTexture2";
createNode vectorRenderGlobals -s -n "vectorRenderGlobals";
createNode lambert -n "lambert2";
createNode shadingEngine -n "lambert2SG";
	setAttr ".ihi" 0;
	setAttr -s 6 ".dsm";
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo1";
createNode animCurveTU -n "LegL_scaleX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.58868139409613618 11 0.98806274830267027 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.99547100067138672 1 1 1;
	setAttr -s 5 ".kiy[1:4]"  -0.095065474510192871 0 0 0;
createNode animCurveTU -n "LegL_scaleY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.58868139409613618 11 0.98806274830267027 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.99547100067138672 1 1 1;
	setAttr -s 5 ".kiy[1:4]"  -0.095065474510192871 0 0 0;
createNode animCurveTU -n "LegL_scaleZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.58868139409613618 11 0.98806274830267027 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.99547100067138672 1 1 1;
	setAttr -s 5 ".kiy[1:4]"  -0.095065474510192871 0 0 0;
createNode animCurveTU -n "ArmR_scaleX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.7453976600753045 11 1.0562891566910428 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.91181463003158569 0.54770028591156006 
		1 0.59496003389358521;
	setAttr -s 5 ".kiy[1:4]"  0.41060212254524231 0.83667469024658203 
		0 -0.80375528335571289;
createNode animCurveTU -n "ArmR_scaleY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.7453976600753045 11 1.0562891566910428 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.91181463003158569 0.54770028591156006 
		1 0.59496003389358521;
	setAttr -s 5 ".kiy[1:4]"  0.41060212254524231 0.83667469024658203 
		0 -0.80375528335571289;
createNode animCurveTU -n "ArmR_scaleZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.7453976600753045 11 1.0562891566910428 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.91181463003158569 0.54770028591156006 
		1 0.59496003389358521;
	setAttr -s 5 ".kiy[1:4]"  0.41060212254524231 0.83667469024658203 
		0 -0.80375528335571289;
createNode animCurveTU -n "ArmL_scaleX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.93427859867794383 11 0.70881991778534192 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.56642645597457886 0.4848875105381012 
		1 0.14165292680263519;
	setAttr -s 5 ".kiy[1:4]"  -0.82411229610443115 -0.87457656860351563 
		0 0.98991644382476807;
createNode animCurveTU -n "ArmL_scaleY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.93427859867794383 11 0.70881991778534192 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.56642645597457886 0.4848875105381012 
		1 0.14165292680263519;
	setAttr -s 5 ".kiy[1:4]"  -0.82411229610443115 -0.87457656860351563 
		0 0.98991644382476807;
createNode animCurveTU -n "ArmL_scaleZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 0.93427859867794383 11 0.70881991778534192 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.56642645597457886 0.4848875105381012 
		1 0.14165292680263519;
	setAttr -s 5 ".kiy[1:4]"  -0.82411229610443115 -0.87457656860351563 
		0 0.98991644382476807;
createNode animCurveTU -n "LegR_scaleX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 1.1207829182146496 11 0.68962055450148196 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.16647572815418243 0.60268932580947876 
		1 0.13305072486400604;
	setAttr -s 5 ".kiy[1:4]"  -0.98604553937911987 -0.79797595739364624 
		0 0.99110925197601318;
createNode animCurveTU -n "LegR_scaleY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 1.1207829182146496 11 0.68962055450148196 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.16647572815418243 0.60268932580947876 
		1 0.13305072486400604;
	setAttr -s 5 ".kiy[1:4]"  -0.98604553937911987 -0.79797595739364624 
		0 0.99110925197601318;
createNode animCurveTU -n "LegR_scaleZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 5 ".ktv[0:4]"  9 1 10 1.1207829182146496 11 0.68962055450148196 
		12 1 13 1;
	setAttr -s 5 ".kit[0:4]"  10 1 1 10 1;
	setAttr -s 5 ".ktl[0:4]" no no no no no;
	setAttr -s 5 ".kix[1:4]"  0.16647572815418243 0.60268932580947876 
		1 0.13305072486400604;
	setAttr -s 5 ".kiy[1:4]"  -0.98604553937911987 -0.79797595739364624 
		0 0.99110925197601318;
createNode animCurveTU -n "Body_scaleX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 2 ".ktv[0:1]"  9 1 13 1;
	setAttr -s 2 ".kit[0:1]"  10 1;
	setAttr -s 2 ".ktl[0:1]" no no;
	setAttr -s 2 ".kix[1]"  1;
	setAttr -s 2 ".kiy[1]"  0;
createNode animCurveTU -n "Body_scaleY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 2 ".ktv[0:1]"  9 1 13 1;
	setAttr -s 2 ".kit[0:1]"  10 1;
	setAttr -s 2 ".ktl[0:1]" no no;
	setAttr -s 2 ".kix[1]"  1;
	setAttr -s 2 ".kiy[1]"  0;
createNode animCurveTU -n "Body_scaleZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 2 ".ktv[0:1]"  9 1 13 1;
	setAttr -s 2 ".kit[0:1]"  10 1;
	setAttr -s 2 ".ktl[0:1]" no no;
	setAttr -s 2 ".kix[1]"  1;
	setAttr -s 2 ".kiy[1]"  0;
createNode animCurveTU -n "Head_scaleX";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 2 ".ktv[0:1]"  9 1 13 1;
	setAttr -s 2 ".kit[0:1]"  10 1;
	setAttr -s 2 ".ktl[0:1]" no no;
	setAttr -s 2 ".kix[1]"  1;
	setAttr -s 2 ".kiy[1]"  0;
createNode animCurveTU -n "Head_scaleY";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 2 ".ktv[0:1]"  9 1 13 1;
	setAttr -s 2 ".kit[0:1]"  10 1;
	setAttr -s 2 ".ktl[0:1]" no no;
	setAttr -s 2 ".kix[1]"  1;
	setAttr -s 2 ".kiy[1]"  0;
createNode animCurveTU -n "Head_scaleZ";
	setAttr ".tan" 5;
	setAttr ".wgt" no;
	setAttr -s 2 ".ktv[0:1]"  9 1 13 1;
	setAttr -s 2 ".kit[0:1]"  10 1;
	setAttr -s 2 ".ktl[0:1]" no no;
	setAttr -s 2 ".kix[1]"  1;
	setAttr -s 2 ".kiy[1]"  0;
createNode animCurveTL -n "ArmL_translateZ";
	setAttr ".tan" 10;
	setAttr ".wgt" no;
	setAttr -s 4 ".ktv[0:3]"  12 -2 13 1 14 1 16 -1;
select -ne :time1;
	setAttr ".o" 16;
	setAttr ".unw" 16;
select -ne :renderPartition;
	setAttr -s 3 ".st";
select -ne :initialShadingGroup;
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultShaderList1;
	setAttr -s 3 ".s";
select -ne :defaultTextureList1;
	setAttr -s 2 ".tx";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 2 ".u";
select -ne :renderGlobalsList1;
select -ne :defaultRenderGlobals;
	setAttr ".outf" 32;
	setAttr ".an" yes;
	setAttr ".ef" 16;
	setAttr ".ep" 2;
	setAttr ".pff" yes;
	setAttr ".peie" 2;
select -ne :defaultRenderQuality;
	setAttr ".eaa" 0;
select -ne :defaultResolution;
	setAttr ".w" 128;
	setAttr ".h" 128;
	setAttr ".pa" 1;
	setAttr ".dar" 1;
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :defaultHardwareRenderGlobals;
	setAttr ".fn" -type "string" "im";
	setAttr ".res" -type "string" "ntsc_4d 646 485 1.333";
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "polySurface2_translateX.o" "Body.tx";
connectAttr "polySurface2_translateY.o" "Body.ty";
connectAttr "polySurface2_translateZ.o" "Body.tz";
connectAttr "polySurface2_rotateX.o" "Body.rx";
connectAttr "polySurface2_rotateY.o" "Body.ry";
connectAttr "polySurface2_rotateZ.o" "Body.rz";
connectAttr "Body_scaleX.o" "Body.sx";
connectAttr "Body_scaleY.o" "Body.sy";
connectAttr "Body_scaleZ.o" "Body.sz";
connectAttr "polySurface3_translateX.o" "Head.tx";
connectAttr "polySurface3_translateY.o" "Head.ty";
connectAttr "polySurface3_rotateX.o" "Head.rx";
connectAttr "polySurface3_rotateY.o" "Head.ry";
connectAttr "polySurface3_rotateZ.o" "Head.rz";
connectAttr "Head_scaleX.o" "Head.sx";
connectAttr "Head_scaleY.o" "Head.sy";
connectAttr "Head_scaleZ.o" "Head.sz";
connectAttr "polySurface4_translateX.o" "LegL.tx";
connectAttr "polySurface4_translateY.o" "LegL.ty";
connectAttr "polySurface4_translateZ.o" "LegL.tz";
connectAttr "polySurface4_rotateX.o" "LegL.rx";
connectAttr "polySurface4_rotateY.o" "LegL.ry";
connectAttr "polySurface4_rotateZ.o" "LegL.rz";
connectAttr "LegL_scaleX.o" "LegL.sx";
connectAttr "LegL_scaleY.o" "LegL.sy";
connectAttr "LegL_scaleZ.o" "LegL.sz";
connectAttr "polySurface5_translateX.o" "ArmL.tx";
connectAttr "polySurface5_translateY.o" "ArmL.ty";
connectAttr "ArmL_translateZ.o" "ArmL.tz";
connectAttr "polySurface5_rotateX.o" "ArmL.rx";
connectAttr "polySurface5_rotateY.o" "ArmL.ry";
connectAttr "polySurface5_rotateZ.o" "ArmL.rz";
connectAttr "ArmL_scaleX.o" "ArmL.sx";
connectAttr "ArmL_scaleY.o" "ArmL.sy";
connectAttr "ArmL_scaleZ.o" "ArmL.sz";
connectAttr "polySurface6_translateX.o" "ArmR.tx";
connectAttr "polySurface6_translateY.o" "ArmR.ty";
connectAttr "polySurface6_rotateX.o" "ArmR.rx";
connectAttr "polySurface6_rotateY.o" "ArmR.ry";
connectAttr "polySurface6_rotateZ.o" "ArmR.rz";
connectAttr "ArmR_scaleX.o" "ArmR.sx";
connectAttr "ArmR_scaleY.o" "ArmR.sy";
connectAttr "ArmR_scaleZ.o" "ArmR.sz";
connectAttr "polySurface7_translateX.o" "LegR.tx";
connectAttr "polySurface7_translateY.o" "LegR.ty";
connectAttr "polySurface7_translateZ.o" "LegR.tz";
connectAttr "polySurface7_rotateX.o" "LegR.rx";
connectAttr "polySurface7_rotateY.o" "LegR.ry";
connectAttr "polySurface7_rotateZ.o" "LegR.rz";
connectAttr "LegR_scaleX.o" "LegR.sx";
connectAttr "LegR_scaleY.o" "LegR.sy";
connectAttr "LegR_scaleZ.o" "LegR.sz";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "lambert2SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "lambert2SG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "place2dTexture1.c" "psdFileTex1.c";
connectAttr "place2dTexture1.tf" "psdFileTex1.tf";
connectAttr "place2dTexture1.rf" "psdFileTex1.rf";
connectAttr "place2dTexture1.mu" "psdFileTex1.mu";
connectAttr "place2dTexture1.mv" "psdFileTex1.mv";
connectAttr "place2dTexture1.s" "psdFileTex1.s";
connectAttr "place2dTexture1.wu" "psdFileTex1.wu";
connectAttr "place2dTexture1.wv" "psdFileTex1.wv";
connectAttr "place2dTexture1.re" "psdFileTex1.re";
connectAttr "place2dTexture1.of" "psdFileTex1.of";
connectAttr "place2dTexture1.r" "psdFileTex1.ro";
connectAttr "place2dTexture1.n" "psdFileTex1.n";
connectAttr "place2dTexture1.vt1" "psdFileTex1.vt1";
connectAttr "place2dTexture1.vt2" "psdFileTex1.vt2";
connectAttr "place2dTexture1.vt3" "psdFileTex1.vt3";
connectAttr "place2dTexture1.vc1" "psdFileTex1.vc1";
connectAttr "place2dTexture1.o" "psdFileTex1.uv";
connectAttr "place2dTexture1.ofs" "psdFileTex1.fs";
connectAttr "place2dTexture2.c" "file1.c";
connectAttr "place2dTexture2.tf" "file1.tf";
connectAttr "place2dTexture2.rf" "file1.rf";
connectAttr "place2dTexture2.mu" "file1.mu";
connectAttr "place2dTexture2.mv" "file1.mv";
connectAttr "place2dTexture2.s" "file1.s";
connectAttr "place2dTexture2.wu" "file1.wu";
connectAttr "place2dTexture2.wv" "file1.wv";
connectAttr "place2dTexture2.re" "file1.re";
connectAttr "place2dTexture2.of" "file1.of";
connectAttr "place2dTexture2.r" "file1.ro";
connectAttr "place2dTexture2.n" "file1.n";
connectAttr "place2dTexture2.vt1" "file1.vt1";
connectAttr "place2dTexture2.vt2" "file1.vt2";
connectAttr "place2dTexture2.vt3" "file1.vt3";
connectAttr "place2dTexture2.vc1" "file1.vc1";
connectAttr "place2dTexture2.o" "file1.uv";
connectAttr "place2dTexture2.ofs" "file1.fs";
connectAttr "psdFileTex1.oc" "lambert2.c";
connectAttr "psdFileTex1.ot" "lambert2.it";
connectAttr "lambert2.oc" "lambert2SG.ss";
connectAttr "LegRShape.iog" "lambert2SG.dsm" -na;
connectAttr "ArmRShape.iog" "lambert2SG.dsm" -na;
connectAttr "ArmLShape.iog" "lambert2SG.dsm" -na;
connectAttr "LegLShape.iog" "lambert2SG.dsm" -na;
connectAttr "HeadShape.iog" "lambert2SG.dsm" -na;
connectAttr "BodyShape.iog" "lambert2SG.dsm" -na;
connectAttr "lambert2SG.msg" "materialInfo1.sg";
connectAttr "lambert2.msg" "materialInfo1.m";
connectAttr "psdFileTex1.msg" "materialInfo1.t" -na;
connectAttr "lambert2SG.pa" ":renderPartition.st" -na;
connectAttr "lambert2.msg" ":defaultShaderList1.s" -na;
connectAttr "psdFileTex1.msg" ":defaultTextureList1.tx" -na;
connectAttr "file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
// End of Character.ma
