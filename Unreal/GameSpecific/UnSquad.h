#ifndef UEVIEWER_UNSQUAD_H
#define UEVIEWER_UNSQUAD_H

struct Link
{
    UObject *NodeA;
    UObject *NodeB;
#if DECLARE_VIEWER_PROPS
    DECLARE_STRUCT(Link)
    BEGIN_PROP_TABLE
		PROP_OBJ(NodeA)
		PROP_OBJ(NodeB)
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

struct TAASLanes
{
    FString LaneName;
    FLinearColor LaneNodesColor;
    TArray<Link> AASLaneLinks;
#if DECLARE_VIEWER_PROPS
    DECLARE_STRUCT(TAASLanes)
    BEGIN_PROP_TABLE
		PROP_STRING(LaneName)
		PROP_STRUC(LaneNodesColor, FLinearColor)
		PROP_ARRAY(AASLaneLinks, "Link")
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class UComponent : public UObject
{
    DECLARE_CLASS(UComponent, UObject)
public:
    UObject *AttachParent;

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
		PROP_OBJ(AttachParent)
		PROP_DROP(bNetAddressable)
		PROP_DROP(CreationMethod)
		PROP_DROP(bVisualizeComponent)
		PROP_DROP(UCSModifiedProperties) // TODO: check
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USceneComponent : public UComponent
{
    DECLARE_CLASS(USceneComponent, UComponent)
public:
    FVector RelativeLocation;
    FRotator RelativeRotation;
    FVector RelativeScale3D;

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
		PROP_VECTOR(RelativeLocation)
		PROP_ROTATOR(RelativeRotation)
		PROP_VECTOR(RelativeScale3D) // TODO: might be wrong, is 0.0 when it should be 1.0

	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQGraphNodeComponent : public UComponent
{
#if DECLARE_VIEWER_PROPS
    DECLARE_CLASS(USQGraphNodeComponent, UComponent)
    BEGIN_PROP_TABLE
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQGraphRAASInitializerComponent : public UComponent
{
    DECLARE_CLASS(USQGraphRAASInitializerComponent, UComponent)
public:
    TArray<Link> DesignOutgoingLinks;

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
		PROP_ARRAY(DesignOutgoingLinks, "Link")
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQRAASLaneInitializer_C : public USQGraphRAASInitializerComponent
{
    TArray<TAASLanes> AASLanes;

#if DECLARE_VIEWER_PROPS
    DECLARE_CLASS(USQRAASLaneInitializer_C, USQGraphRAASInitializerComponent)
	BEGIN_PROP_TABLE
		PROP_ARRAY(AASLanes, "TAASLanes")
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};


class USphereComponent : public USceneComponent
{
    float SphereRadius;
    byte SphereMobility;
    byte Mobility;

#if DECLARE_VIEWER_PROPS
    DECLARE_CLASS(USphereComponent, USceneComponent)
	BEGIN_PROP_TABLE
	    PROP_FLOAT(SphereRadius)
	    PROP_BYTE(SphereMobility)
	    PROP_BYTE(Mobility)

	    PROP_DROP(BodyInstance) // TODO: check
	    PROP_DROP(AreaClass) // TODO: check
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class UActor : public UObject
{
    DECLARE_CLASS(UActor, UObject)
public:
    FString ActorLabel;
    FName FolderPath;
    UObject *DefaultSceneRoot;
    UObject *RootComponent;

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
		PROP_STRING(ActorLabel)
		PROP_NAME(FolderPath)
		PROP_OBJ(RootComponent)
		PROP_OBJ(DefaultSceneRoot)

		PROP_DROP(BlueprintCreatedComponents) // TODO: check
	    PROP_DROP(InstanceComponents) // TODO: check
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS

};

class UBP_CaptureZone_C : public UActor
{
    DECLARE_CLASS(UBP_CaptureZone_C, UActor)
public:
    UObject *SQCaptureZone;
#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	    PROP_OBJ(SQCaptureZone)
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class UBP_CaptureZoneInvasion_C : public UActor
{
    DECLARE_CLASS(UBP_CaptureZoneInvasion_C, UActor)
public:
    UObject *SQCaptureZoneInvasion;
#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	    PROP_OBJ(SQCaptureZoneInvasion)
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class UBP_CaptureZoneMain_C : public UBP_CaptureZone_C
{
    UObject *Sphere;
    UObject *SQCaptureZoneResource;

#if DECLARE_VIEWER_PROPS
    DECLARE_CLASS(UBP_CaptureZoneMain_C, UBP_CaptureZone_C)
	BEGIN_PROP_TABLE
	    PROP_OBJ(Sphere)
	    PROP_OBJ(SQCaptureZoneResource)

	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class UBP_CaptureZoneCluster_C : public UActor
{
    UObject *SQGraphNode;

#if DECLARE_VIEWER_PROPS
    DECLARE_CLASS(UBP_CaptureZoneCluster_C, UActor)
	BEGIN_PROP_TABLE
		PROP_OBJ(SQGraphNode)
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQCaptureZoneComponent : public UComponent
{
    DECLARE_CLASS(USQCaptureZoneComponent, UComponent)
public:
    FString FlagName;
    UObject *StateObject;
    byte initialTeam;

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	    PROP_OBJ(StateObject)
	    PROP_STRING(FlagName)
	    PROP_BYTE(initialTeam)
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQCaptureZoneInvasionComponent : public USQCaptureZoneComponent
{
    DECLARE_CLASS(USQCaptureZoneInvasionComponent, USQCaptureZoneComponent)

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQCaptureZoneResourceComponent: public UComponent
{
    DECLARE_CLASS(USQCaptureZoneResourceComponent, UComponent)

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class USQMarker : public UActor
{
    DECLARE_CLASS(USQMarker, UActor)
public: // TODO: public everywhere
#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

class UBP_CornerMarker_C : public USQMarker
{
    DECLARE_CLASS(UBP_CornerMarker_C, USQMarker)

#if DECLARE_VIEWER_PROPS
    BEGIN_PROP_TABLE
	END_PROP_TABLE
#endif // DECLARE_VIEWER_PROPS
};

#define REGISTER_SQUAD_CLASSES \
    REGISTER_CLASS(Link) \
    REGISTER_CLASS(TAASLanes) \
    REGISTER_CLASS(USceneComponent) \
    REGISTER_CLASS(USQGraphNodeComponent) \
    REGISTER_CLASS(USphereComponent) \
    REGISTER_CLASS(UBP_CaptureZoneCluster_C) \
    REGISTER_CLASS(UBP_CaptureZoneMain_C) \
    REGISTER_CLASS(UBP_CaptureZone_C) \
    REGISTER_CLASS(UBP_CaptureZoneInvasion_C) \
    REGISTER_CLASS(USQCaptureZoneComponent) \
    REGISTER_CLASS(USQCaptureZoneInvasionComponent) \
    REGISTER_CLASS(USQCaptureZoneResourceComponent) \
    REGISTER_CLASS(USQGraphRAASInitializerComponent) \
    REGISTER_CLASS(USQRAASLaneInitializer_C) \
    REGISTER_CLASS(UActor) \
    REGISTER_CLASS(USQMarker) \
    REGISTER_CLASS(UBP_CornerMarker_C)

#endif //UEVIEWER_UNSQUAD_H
