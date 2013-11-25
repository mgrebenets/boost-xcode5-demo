//
//  ModelMacro.h
//  ipolypus-model
//
//  Created by Maksym Grebenets on 21/01/13.
//  Copyright (c) 2013 i4nApps. All rights reserved.
//

#ifndef model_ModelMacro_h
#define model_ModelMacro_h

#if DEBUG
#define MODEL_LOG(_format_, ...) printf((_format_), ##__VA_ARGS__)
#else
#define MODEL_LOG(_format_, ...) 
#endif

#endif
