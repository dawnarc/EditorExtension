// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "ConvertMeshWidget.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYEXTENDER_API UConvertMeshWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:

	UConvertMeshWidget();

	void NativeConstruct() override;

protected:

	UFUNCTION()
        void OnBtnConvertClick();
};
