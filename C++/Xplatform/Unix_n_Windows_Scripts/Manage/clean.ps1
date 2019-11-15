#!/usr/bin/env pwsh

Set-Location $PSScriptRoot


#                     I hardcoded path for security reasons
$(Get-ChildItem -Path C:\Source\Libraries -Recurse -Force).foreach({ 
    # -Force to find hidden files
    $name = $_.FullName    
    if($_.PSIsContainer -and $name -match "^.*\\(Release|Debug|Build|out|\.vs|.vscode|cmake-build-debug|.idea)$"){
        if(Test-Path -Path $name){
            Write-Host $name;
            Remove-Item $_.FullName -Recurse -Force;
        }
    }
});
