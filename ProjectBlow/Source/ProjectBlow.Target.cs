// Developed By Group 1 of Master's Collab 2019-2020 at Staffordshire University

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBlowTarget : TargetRules
{
	public ProjectBlowTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ProjectBlow" } );
	}
}
