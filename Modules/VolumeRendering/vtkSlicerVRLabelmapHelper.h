#ifndef __vtkSlicerVRLabelmapHelper_h
#define __vtkSlicerVRLabelmapHelper_h

#include "vtkVolumeRenderingModule.h"
#include "vtkSlicerVRHelper.h"
#include <string>

class vtkSlicerLabelMapWidget;
class vtkSlicerFixedPointVolumeRayCastMapper;
class vtkVolumeRayCastMapper;
class vtkKWVolumeMaterialPropertyWidget;
class VTK_VOLUMERENDERINGMODULE_EXPORT vtkSlicerVRLabelmapHelper :public vtkSlicerVRHelper
{
public:
    static vtkSlicerVRLabelmapHelper *New();
    vtkTypeRevisionMacro(vtkSlicerVRLabelmapHelper,vtkSlicerVRHelper);
    virtual void Init(vtkVolumeRenderingModuleGUI *gui);
    virtual void InitializePipelineNewCurrentNode();
    virtual void UpdateGUIElements(void);
    virtual void Rendering(void);
    virtual void UpdateRendering(void);
    void ScheduleRender(int stage);
    void SetButtonDown(int _arg)
    {
        vtkSlicerVRHelperDebug("setbutton %d",_arg);
        this->ButtonDown=(_arg);
    }
    //vtkSetMacro(ButtonDown,int);
protected:
    int ButtonDown;
    int CurrentStage;
    float OldSampleDistance;
    //BTX
    std::string ScheduledRenderID;
    //ETX
    vtkSlicerVRLabelmapHelper(void);
    ~vtkSlicerVRLabelmapHelper(void);
    vtkSlicerVRLabelmapHelper(const vtkSlicerVRLabelmapHelper&);//not implemented
    void operator=(const vtkSlicerVRLabelmapHelper&);//not implemented

    vtkKWVolumeMaterialPropertyWidget *VMPW_Shading;
    vtkSlicerLabelMapWidget *LM_OptionTree;
    vtkSlicerFixedPointVolumeRayCastMapper *MapperRaycast;
    vtkVolumeRayCastMapper *MapperRaycastHighDetail;

    virtual void ProcessVolumeRenderingEvents(vtkObject *caller,unsigned long eid,void *callData);

    void UpdateLM();
    void CheckAbort(void);
    int ProgressLock;
};
#endif
