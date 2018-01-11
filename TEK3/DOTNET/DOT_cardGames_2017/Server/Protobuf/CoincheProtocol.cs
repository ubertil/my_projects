// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CoincheProtocol.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Coinche.Google.Protobuf {

  /// <summary>Holder for reflection information generated from CoincheProtocol.proto</summary>
  public static partial class CoincheProtocolReflection {

    #region Descriptor
    /// <summary>File descriptor for CoincheProtocol.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static CoincheProtocolReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChVDb2luY2hlUHJvdG9jb2wucHJvdG8SB0NvaW5jaGUiGwoLR2FtZVJlcXVl",
            "c3QSDAoEcGxheRgBIAEoCSI1CgxHYW1lUmVzcG9uc2USFAoMcmVzcG9uc2VD",
            "b2RlGAEgASgNEg8KB21lc3NhZ2UYAiABKAlCHEgBqgIXQ29pbmNoZS5Hb29n",
            "bGUuUHJvdG9idWZiBnByb3RvMw=="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Coinche.Google.Protobuf.GameRequest), global::Coinche.Google.Protobuf.GameRequest.Parser, new[]{ "Play" }, null, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Coinche.Google.Protobuf.GameResponse), global::Coinche.Google.Protobuf.GameResponse.Parser, new[]{ "ResponseCode", "Message" }, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  public sealed partial class GameRequest : pb::IMessage<GameRequest> {
    private static readonly pb::MessageParser<GameRequest> _parser = new pb::MessageParser<GameRequest>(() => new GameRequest());
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<GameRequest> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Coinche.Google.Protobuf.CoincheProtocolReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public GameRequest() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public GameRequest(GameRequest other) : this() {
      play_ = other.play_;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public GameRequest Clone() {
      return new GameRequest(this);
    }

    /// <summary>Field number for the "play" field.</summary>
    public const int PlayFieldNumber = 1;
    private string play_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public string Play {
      get { return play_; }
      set {
        play_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as GameRequest);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(GameRequest other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Play != other.Play) return false;
      return true;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Play.Length != 0) hash ^= Play.GetHashCode();
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void WriteTo(pb::CodedOutputStream output) {
      if (Play.Length != 0) {
        output.WriteRawTag(10);
        output.WriteString(Play);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (Play.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Play);
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(GameRequest other) {
      if (other == null) {
        return;
      }
      if (other.Play.Length != 0) {
        Play = other.Play;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 10: {
            Play = input.ReadString();
            break;
          }
        }
      }
    }

  }

  public sealed partial class GameResponse : pb::IMessage<GameResponse> {
    private static readonly pb::MessageParser<GameResponse> _parser = new pb::MessageParser<GameResponse>(() => new GameResponse());
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<GameResponse> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Coinche.Google.Protobuf.CoincheProtocolReflection.Descriptor.MessageTypes[1]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public GameResponse() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public GameResponse(GameResponse other) : this() {
      responseCode_ = other.responseCode_;
      message_ = other.message_;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public GameResponse Clone() {
      return new GameResponse(this);
    }

    /// <summary>Field number for the "responseCode" field.</summary>
    public const int ResponseCodeFieldNumber = 1;
    private uint responseCode_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint ResponseCode {
      get { return responseCode_; }
      set {
        responseCode_ = value;
      }
    }

    /// <summary>Field number for the "message" field.</summary>
    public const int MessageFieldNumber = 2;
    private string message_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public string Message {
      get { return message_; }
      set {
        message_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as GameResponse);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(GameResponse other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (ResponseCode != other.ResponseCode) return false;
      if (Message != other.Message) return false;
      return true;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (ResponseCode != 0) hash ^= ResponseCode.GetHashCode();
      if (Message.Length != 0) hash ^= Message.GetHashCode();
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void WriteTo(pb::CodedOutputStream output) {
      if (ResponseCode != 0) {
        output.WriteRawTag(8);
        output.WriteUInt32(ResponseCode);
      }
      if (Message.Length != 0) {
        output.WriteRawTag(18);
        output.WriteString(Message);
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (ResponseCode != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(ResponseCode);
      }
      if (Message.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Message);
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(GameResponse other) {
      if (other == null) {
        return;
      }
      if (other.ResponseCode != 0) {
        ResponseCode = other.ResponseCode;
      }
      if (other.Message.Length != 0) {
        Message = other.Message;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            input.SkipLastField();
            break;
          case 8: {
            ResponseCode = input.ReadUInt32();
            break;
          }
          case 18: {
            Message = input.ReadString();
            break;
          }
        }
      }
    }

  }

  #endregion

}

#endregion Designer generated code
