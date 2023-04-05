#include "TWDDismemberData.h"

FTWDDismemberData::FTWDDismemberData() {
    this->LimbCapClass = NULL;
    this->DroppedLimbClass = NULL;
    this->bAdvancedDismemberEnabled = false;
    this->AdvancedDismemberSeverNormalRatio = 0.00f;
    this->AdvancedDismemberImpulseLocNormalBias = 0.00f;
    this->AdvancedDismemberMaxAngleOfDeviationFromBoneDirection = 0.00f;
    this->AdvancedDismemberMaxAngleOfDeviationFromBoneDirectionForTransverseCut = 0.00f;
    this->DroppedLimbAdvancedClass = NULL;
    this->bAdvancedDismemberOnly = false;
    this->SeverHitReactType = EHitReactType::None;
    this->AdvancedDismemberResistanceScale = 0.00f;
    this->CutBoneIndex = 0;
}

