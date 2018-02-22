// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AI = OwnerComp.GetAIOwner();
	auto AI_Pawn = AI->GetPawn();
	auto pp = AI_Pawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(pp)){ return EBTNodeResult::Failed; }
	
	auto PatrolPoint =pp->PatrolPoints;

	if (PatrolPoint.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("no one"));
			return EBTNodeResult::Failed;
	}
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WayPoint.SelectedKeyName, PatrolPoint[Index]);
	 auto NextIndex = (Index + 1) % PatrolPoint.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
 // UE_LOG(LogTemp, Warning, TEXT("%i"), Index);
	return EBTNodeResult::Succeeded;
}

