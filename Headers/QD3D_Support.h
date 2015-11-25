//// qd3d_support.h//#ifndef QD3D_SUP#define QD3D_SUP#include <QD3D.h>#include <QD3DCamera.h>#include <QD3DDrawContext.h>#include <QD3DRenderer.h>#include <QD3DShader.h>#include <QD3DStyle.h>#include <QD3DView.h>#define	DEFAULT_FPS			3#define	MAX_FILL_LIGHTS		4typedef	struct{	WindowPtr				displayWindow;	TQ3ObjectType			rendererType;	TQ3ColorARGB			clearColor;	Rect					paneClip;			// not pane size, but clip:  left = amount to clip off left}QD3DViewDefType;typedef	struct{	TQ3InterpolationStyle	interpolation;	TQ3BackfacingStyle		backfacing;	TQ3FillStyle			fill;	TQ3ObjectType			illuminationType;}QD3DStyleDefType;typedef struct{	TQ3Point3D				from;	TQ3Point3D				to;	TQ3Vector3D				up;	float					hither;	float					yon;	float					fov;}QD3DCameraDefType;typedef	struct{	float			ambientBrightness;	TQ3ColorRGB		ambientColor;	long			numFillLights;	TQ3Vector3D		fillDirection[MAX_FILL_LIGHTS];	TQ3ColorRGB		fillColor[MAX_FILL_LIGHTS];	float			fillBrightness[MAX_FILL_LIGHTS];}QD3DLightDefType;		/* QD3DSetupInputType */		typedef struct{	QD3DViewDefType			view;	QD3DStyleDefType		styles;	QD3DCameraDefType		camera;	QD3DLightDefType		lights;}QD3DSetupInputType;		/* QD3DSetupOutputType */typedef struct{	TQ3ViewObject			viewObject;	TQ3ShaderObject			shaderObject;	TQ3StyleObject			interpolationStyle;	TQ3StyleObject			backfacingStyle;	TQ3StyleObject			fillStyle;	TQ3CameraObject			cameraObject;	// another ref is in viewObject, this one's just for convenience!	TQ3GroupObject			lightGroup;		// another ref is in viewObject, this one's just for convenience!	TQ3DrawContextObject	drawContext;	// another ref is in viewObject, this one's just for convenience!	WindowPtr				window;	Rect					paneClip;			// not pane size, but clip:  left = amount to clip off left}QD3DSetupOutputType;//===========================================================extern	void QD3D_SetupWindow(QD3DSetupInputType *setupDefPtr, QD3DSetupOutputType *outputPtr);extern	void QD3D_DisposeWindowSetup(QD3DSetupOutputType *data);extern	void QD3D_ChangeDrawSize(QD3DSetupOutputType *setupInfo);extern	void QD3D_DrawScene(QD3DSetupOutputType *setupInfo, void (*drawRoutine)(QD3DSetupOutputType *));extern	float	QD3D_CalcFramesPerSecond(void);extern	Boolean QD3D_ShowError(Str255 errString, Boolean showWarnings);extern	void QD3D_ShowRecentError(void);extern	void QD3D_DoMemoryError(void);extern	TQ3SurfaceShaderObject	QD3D_GetTextureMap(long	textureRezID, FSSpec *);#endif