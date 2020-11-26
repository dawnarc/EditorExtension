// Fill out your copyright notice in the Description page of Project Settings.


#include "ConvertMeshWidget.h"

#include "Components/Button.h"
#include "MeshUtilities.h"
#include "EditorLevelLibrary.h"

UConvertMeshWidget::UConvertMeshWidget()
{
    
}

void UConvertMeshWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (UButton* btn = Cast<UButton>(GetWidgetFromName("BtnConvert")))
    {
        FScriptDelegate Del;
        Del.BindUFunction(this, "OnBtnConvertClick");
        btn->OnClicked.Add(Del);
    }
}

void UConvertMeshWidget::OnBtnConvertClick()
{
    TArray<class AActor*> SelectActors = UEditorLevelLibrary::GetSelectedLevelActors();

    TArray<class UMeshComponent*> SelectMeshes;
    for(AActor* Actor : SelectActors)
    {
        USceneComponent* Comp = Actor->GetRootComponent();
        if(Comp->IsA(UMeshComponent::StaticClass()))
        {
            SelectMeshes.Add(Cast<UMeshComponent>(Comp));
        }
    }
    
    IMeshUtilities& MeshUtilities = FModuleManager::Get().LoadModuleChecked<IMeshUtilities>(TEXT("MeshUtilities"));
    MeshUtilities.ConvertMeshesToStaticMesh(SelectMeshes);
}