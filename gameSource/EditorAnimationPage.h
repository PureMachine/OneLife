#ifndef EDITOR_ANIMATION_PAGE_INCLUDED
#define EDITOR_ANIMATION_PAGE_INCLUDED




#include "minorGems/ui/event/ActionListener.h"
#include "minorGems/util/SimpleVector.h"

#include "minorGems/game/game.h"


#include "GamePage.h"
#include "TextButton.h"
#include "TextField.h"

#include "CheckboxButton.h"

#include "ValueSlider.h"


#include "Picker.h"

#include "animationBank.h"
#include "objectBank.h"
#include "keyLegend.h"


#define NUM_ANIM_CHECKBOXES 3
#define NUM_ANIM_SLIDERS 13



typedef struct WalkAnimationRecord {
    } WalkAnimationRecord;



class EditorAnimationPage : public GamePage, public ActionListener {
        
    public:
        EditorAnimationPage();
        ~EditorAnimationPage();        

        void clearClothing();
        
        void clearUseOfObject( int inObjectID );

        void objectLayersChanged( int inObjectID );
        

        virtual void actionPerformed( GUIComponent *inTarget );
        
        virtual void drawUnderComponents( doublePair inViewCenter, 
                                          double inViewSize );
        
        virtual void step();
  
        virtual void makeActive( char inFresh );
        

        virtual void pointerMove( float inX, float inY );
        virtual void pointerDown( float inX, float inY );
        virtual void pointerDrag( float inX, float inY );
        virtual void pointerUp( float inX, float inY );
        
        virtual void keyDown( unsigned char inASCII );
        virtual void specialKeyDown( int inKeyCode );
        
    protected:
        
        SpriteHandle mCenterMarkSprite;

        SpriteHandle mGroundSprite;
        

        TextButton mObjectEditorButton;

        TextButton mSaveButton;
        TextButton mDeleteButton;
        Picker mObjectPicker;

        ValueSlider mPersonAgeSlider;

        ValueSlider mTestSpeedSlider;
        double mLastTestSpeed;

        double mFrameTimeOffset;
        

        CheckboxButton *mCheckboxes[NUM_ANIM_CHECKBOXES];
        const char *mCheckboxNames[NUM_ANIM_CHECKBOXES];
        AnimType mCheckboxAnimTypes[NUM_ANIM_CHECKBOXES];
        
        ValueSlider *mSliders[ NUM_ANIM_SLIDERS ];
        
        CheckboxButton mReverseRotationCheckbox;

        int mCurrentObjectID;
        int mCurrentSlotDemoID;

        char mFlipDraw;
        

        AnimationRecord *mCurrentAnim[ endAnimType ];
        
        AnimationRecord *mWiggleAnim;
        
        double mWiggleFade;
        int mWiggleSpriteOrSlot;


        AnimType mCurrentType;
        AnimType mLastType;

        double mLastTypeFade;
        int mLastTypeFrozenRotFrameCount;
        

        int mCurrentSpriteOrSlot;

        char mSettingRotCenter;
        
        TextButton mPickSlotDemoButton;
        
        char mPickingSlotDemo;

        TextButton mClearSlotDemoButton;
        

        TextButton mPickClothingButton;
        
        char mPickingClothing;
        
        ClothingSet mClothingSet;
        
        ObjectRecord **mNextShoeToFill;
        ObjectRecord **mOtherShoe;
        


        TextButton mClearClothingButton;

        


        SpriteAnimationRecord mCopyBuffer;

        SimpleVector<SpriteAnimationRecord> mChainCopyBuffer;

        SimpleVector<SpriteAnimationRecord> mAllCopyBufferSprites;
        SimpleVector<SpriteAnimationRecord> mAllCopyBufferSlots;
        

        char mWalkCopied;
        SpriteAnimationRecord mCopiedHeadAnim;
        SpriteAnimationRecord mCopiedBodyAnim;
        
        SpriteAnimationRecord mCopiedBackFootAnim;
        SpriteAnimationRecord mCopiedFrontFootAnim;
        
        SpriteAnimationRecord mCopiedBackHandAnim;
        SpriteAnimationRecord mCopiedFrontHandAnim;


        TextButton mCopyButton;
        TextButton mCopyChainButton;
        TextButton mCopyWalkButton;
        TextButton mCopyAllButton;


        TextButton mPasteButton;
        TextButton mClearButton;
        

        TextButton mNextSpriteOrSlotButton;
        TextButton mPrevSpriteOrSlotButton;
        
        void checkNextPrevVisible();
        

        void updateAnimFromSliders();
        void updateSlidersFromAnim();


        int mFrameCount;

        void freeCurrentAnim();
        void populateCurrentAnim();
        

        void setWiggle();
        
        int getClosestSpriteOrSlot( float inX, float inY );
        

        
        SpriteAnimationRecord *getRecordForCurrentSlot(
            char *outIsSprite = NULL );
        

        KeyLegend mKeyLegend;
    };



#endif
