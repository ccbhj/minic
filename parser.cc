// A Bison parser, made by GNU Bison 3.6.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"

// Second part of user prologue.
#line 105 "parser.y"


#line 48 "parser.cc"

// Unqualified %code blocks.
#line 37 "parser.y"

#include "tokens.h"
#include "ast.h"
#include <iostream>
#include "context.h"
#include "driver.h"



#undef yylex
#define yylex drv.scanner->yylex

using ccbhj::BiOpt;
using ccbhj::UaOpt;
using ccbhj::Type;
using std::cout;
using std::endl;

#line 70 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.y"
namespace ccbhj {
#line 163 "parser.cc"

  /// Build a parser object.
  Parser::Parser (Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 33 "parser.y"
{
    yyla.location.begin.filename = yyla.location.end.filename = &drv.output;
}

#line 501 "parser.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 113 "parser.y"
                          { drv.ctx->programBlock = (yystack_[0].value.BLOCK); }
#line 639 "parser.cc"
    break;

  case 3:
#line 114 "parser.y"
                { cout << "empty file to parse" << endl; }
#line 645 "parser.cc"
    break;

  case 4:
#line 117 "parser.y"
               { (yylhs.value.IDENT) = new IdentifierNode((yystack_[0].value.STR), yystack_[0].location.begin.line); }
#line 651 "parser.cc"
    break;

  case 5:
#line 121 "parser.y"
                               {    (yylhs.value.BLOCK) = new BlockNode(); (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 657 "parser.cc"
    break;

  case 6:
#line 122 "parser.y"
                                                   { (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 663 "parser.cc"
    break;

  case 7:
#line 125 "parser.y"
                              { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 669 "parser.cc"
    break;

  case 8:
#line 126 "parser.y"
                               { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 675 "parser.cc"
    break;

  case 9:
#line 129 "parser.y"
                                  { (yylhs.value.STMT) = new Formal((yystack_[2].value.TYPE), (yystack_[1].value.IDENT));}
#line 681 "parser.cc"
    break;

  case 10:
#line 130 "parser.y"
                                                              { (yylhs.value.STMT) = new
               ArrayFormal((yystack_[5].value.TYPE), (yystack_[4].value.IDENT), std::stoi(*(yystack_[2].value.STR))); delete (yystack_[2].value.STR); }
#line 688 "parser.cc"
    break;

  case 11:
#line 132 "parser.y"
                                                           { cout << "array length must be a const integer" << endl; yyerrok; }
#line 694 "parser.cc"
    break;

  case 12:
#line 136 "parser.y"
              { (yylhs.value.TYPE) = Type::int_; }
#line 700 "parser.cc"
    break;

  case 13:
#line 139 "parser.y"
                                                             {
                  (yylhs.value.STMT) = new FuncDeclNode(Type::void_, (yystack_[4].value.IDENT), (yystack_[2].value.FORMALS), (yystack_[0].value.BLOCK)); 
                    yyerrok;
                  }
#line 709 "parser.cc"
    break;

  case 14:
#line 143 "parser.y"
                                                                 {
                  (yylhs.value.STMT) = new FuncDeclNode((yystack_[5].value.TYPE), (yystack_[4].value.IDENT), (yystack_[2].value.FORMALS), (yystack_[0].value.BLOCK)); 
                    yyerrok;
                  }
#line 718 "parser.cc"
    break;

  case 15:
#line 147 "parser.y"
                                                          { cout << "invalid return type" << endl; yyerrok; }
#line 724 "parser.cc"
    break;

  case 16:
#line 151 "parser.y"
               { /* no param */ (yylhs.value.FORMALS) = nullptr;}
#line 730 "parser.cc"
    break;

  case 17:
#line 152 "parser.y"
             { (yylhs.value.FORMALS) = nullptr;}
#line 736 "parser.cc"
    break;

  case 18:
#line 153 "parser.y"
        { (yylhs.value.FORMALS) = (yystack_[0].value.FORMALS); }
#line 742 "parser.cc"
    break;

  case 19:
#line 156 "parser.y"
                  { (yylhs.value.FORMALS) = new Formals(); (yylhs.value.FORMALS)->formals.push_back(static_cast<Formal*>((yystack_[0].value.STMT))); }
#line 748 "parser.cc"
    break;

  case 20:
#line 157 "parser.y"
                                   { (yystack_[2].value.FORMALS)->formals.push_back(static_cast<Formal*>((yystack_[0].value.STMT))); }
#line 754 "parser.cc"
    break;

  case 21:
#line 161 "parser.y"
                   { (yylhs.value.STMT) = new Formal((yystack_[1].value.TYPE), (yystack_[0].value.IDENT)); }
#line 760 "parser.cc"
    break;

  case 22:
#line 162 "parser.y"
                                     {(yylhs.value.STMT) = new ArrayFormal((yystack_[3].value.TYPE), (yystack_[2].value.IDENT)); }
#line 766 "parser.cc"
    break;

  case 23:
#line 166 "parser.y"
                                                    { (yylhs.value.BLOCK) = (yystack_[2].value.BLOCK); (yystack_[2].value.BLOCK)->statements.push_back((yystack_[1].value.STMT)); }
#line 772 "parser.cc"
    break;

  case 24:
#line 167 "parser.y"
                                       { (yylhs.value.BLOCK) = (yystack_[1].value.BLOCK); }
#line 778 "parser.cc"
    break;

  case 25:
#line 168 "parser.y"
                                              { (yylhs.value.BLOCK) = nullptr;}
#line 784 "parser.cc"
    break;

  case 26:
#line 171 "parser.y"
                { (yylhs.value.BLOCK) = new BlockNode(); (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 790 "parser.cc"
    break;

  case 27:
#line 172 "parser.y"
                          { (yystack_[1].value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 796 "parser.cc"
    break;

  case 28:
#line 175 "parser.y"
      { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 802 "parser.cc"
    break;

  case 29:
#line 176 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 808 "parser.cc"
    break;

  case 30:
#line 177 "parser.y"
                      { (yylhs.value.STMT) = (yystack_[0].value.BLOCK);  }
#line 814 "parser.cc"
    break;

  case 31:
#line 178 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 820 "parser.cc"
    break;

  case 32:
#line 179 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 826 "parser.cc"
    break;

  case 33:
#line 180 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 832 "parser.cc"
    break;

  case 34:
#line 184 "parser.y"
                                                         {(yylhs.value.STMT) = new SelectNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
#line 838 "parser.cc"
    break;

  case 35:
#line 185 "parser.y"
                                           {(yylhs.value.STMT) = new SelectNode((yystack_[4].value.EXPR), (yystack_[2].value.STMT), (yystack_[0].value.STMT)); }
#line 844 "parser.cc"
    break;

  case 36:
#line 188 "parser.y"
                     { (yylhs.value.STMT) = new ExpStmtNode((yystack_[1].value.EXPR)); }
#line 850 "parser.cc"
    break;

  case 37:
#line 189 "parser.y"
               { (yylhs.value.STMT) = nullptr; }
#line 856 "parser.cc"
    break;

  case 38:
#line 192 "parser.y"
                                              { (yylhs.value.STMT) = new WhileNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
#line 862 "parser.cc"
    break;

  case 39:
#line 195 "parser.y"
                          { (yylhs.value.STMT) = new ReturnNode(); }
#line 868 "parser.cc"
    break;

  case 40:
#line 196 "parser.y"
                              { (yylhs.value.STMT) = new ReturnNode((yystack_[1].value.EXPR)); }
#line 874 "parser.cc"
    break;

  case 41:
#line 199 "parser.y"
                                      { (yylhs.value.IDENT) = new ArrayRef((yystack_[3].value.IDENT), (yystack_[1].value.EXPR)); }
#line 880 "parser.cc"
    break;

  case 42:
#line 201 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
#line 886 "parser.cc"
    break;

  case 43:
#line 202 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[1].value.EXPR);}
#line 892 "parser.cc"
    break;

  case 44:
#line 203 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::plus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 898 "parser.cc"
    break;

  case 45:
#line 204 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::minus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 904 "parser.cc"
    break;

  case 46:
#line 205 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::mul, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 910 "parser.cc"
    break;

  case 47:
#line 206 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::div, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 916 "parser.cc"
    break;

  case 48:
#line 207 "parser.y"
                             { (yylhs.value.EXPR) = new UnaryOperator(UaOpt::neg, (yystack_[0].value.EXPR));}
#line 922 "parser.cc"
    break;

  case 49:
#line 208 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR)); }
#line 928 "parser.cc"
    break;

  case 50:
#line 209 "parser.y"
                             { (yylhs.value.EXPR) = new MethodCallNode((yystack_[3].value.IDENT), (yystack_[1].value.ARGS)); }
#line 934 "parser.cc"
    break;

  case 51:
#line 210 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR));}
#line 940 "parser.cc"
    break;

  case 52:
#line 211 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
#line 946 "parser.cc"
    break;

  case 53:
#line 212 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.EXPR);}
#line 952 "parser.cc"
    break;

  case 54:
#line 213 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.IDENT); }
#line 958 "parser.cc"
    break;

  case 55:
#line 217 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::less, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 964 "parser.cc"
    break;

  case 56:
#line 218 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::greater,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 970 "parser.cc"
    break;

  case 57:
#line 219 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::equal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 976 "parser.cc"
    break;

  case 58:
#line 220 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::nequal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 982 "parser.cc"
    break;

  case 59:
#line 221 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::eless,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 988 "parser.cc"
    break;

  case 60:
#line 222 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::egreater ,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
#line 994 "parser.cc"
    break;

  case 61:
#line 225 "parser.y"
                    { (yylhs.value.EXPR) = new NumNode(std::stoi(*(yystack_[0].value.STR))); delete (yystack_[0].value.STR); }
#line 1000 "parser.cc"
    break;

  case 62:
#line 228 "parser.y"
             { (yylhs.value.ARGS) = nullptr; }
#line 1006 "parser.cc"
    break;

  case 63:
#line 229 "parser.y"
            { (yylhs.value.ARGS) = new ArgsNode(); (yylhs.value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 1012 "parser.cc"
    break;

  case 64:
#line 230 "parser.y"
                      { (yystack_[2].value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 1018 "parser.cc"
    break;


#line 1022 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char Parser::yypact_ninf_ = -70;

  const signed char Parser::yytable_ninf_ = -4;

  const short
  Parser::yypact_[] =
  {
      61,    10,    27,   -70,    43,   108,   -70,   -70,    27,   -70,
      47,   -70,    45,   -70,   -70,     4,    27,    54,    85,   -70,
      85,    66,    57,    60,   -70,    74,    68,   -70,    81,    79,
     195,   195,    50,    88,   198,   -70,   -70,    83,    46,   -70,
      60,    47,    60,    92,   -70,   140,   -70,   195,   195,   195,
     195,    99,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   -70,   -70,   -70,   101,   193,   102,   -70,    27,
     -70,    76,   -70,   -70,   -70,   -70,   -70,   107,   -70,   -70,
     -70,   -70,   -70,   219,   219,    -5,   209,   219,   -70,    -2,
      -2,   -70,   -70,   118,   118,   118,   118,   118,   118,   195,
     -70,   125,   195,    11,   -70,   -70,   104,   -70,   195,   -70,
     -70,   155,   -70,   170,   -70,   219,    93,    93,    90,   -70,
      93,   -70
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,    12,     0,     0,     5,     7,     0,     8,
       0,     4,     0,     1,     6,     0,     0,     0,    16,     9,
      16,     0,    21,     0,    17,     0,    18,    19,     0,    61,
       0,     0,    54,    53,     0,    42,    52,     0,     0,    15,
       0,     0,     0,     0,    61,     0,    48,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    37,    25,     0,     0,     0,    29,     0,
      30,     0,    26,    31,    28,    32,    33,     0,    13,    20,
      14,    10,    43,    49,    63,     0,     0,    51,    11,    44,
      45,    46,    47,    56,    55,    57,    59,    60,    58,     0,
      39,     0,     0,     0,    24,    27,    33,    36,     0,    50,
      41,     0,    40,     0,    23,    64,     0,     0,    34,    38,
       0,    35
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -70,   -70,    -1,   -70,   113,    41,     3,   -70,   100,   -70,
       1,   -18,   -70,   -69,   -70,   -70,   -70,    67,   -70,   -21,
     -70,   -70,   -70
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,    32,     5,     6,    68,    69,     9,    25,    26,
      27,    70,    71,    72,    73,    74,    75,    76,    33,    77,
      35,    36,    85
  };

  const signed char
  Parser::yytable_[] =
  {
      34,    12,   105,     8,   108,    39,   109,    15,     8,    45,
      46,    17,    19,    16,    20,    22,    54,    55,    21,    19,
      10,    16,    78,    16,    80,    21,    83,    84,    86,    87,
      11,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     7,    79,    13,    16,   101,     7,   118,   119,    11,
      44,   121,     3,     3,    63,    18,    30,    47,    64,    38,
      48,    -3,     1,    31,    49,    23,     2,     3,   103,    11,
      29,    37,    65,    38,    66,    67,    30,    41,   111,    11,
      44,   113,     3,    31,    63,    40,    30,   115,   104,    38,
      24,     3,    42,    31,    43,    50,    11,    44,    62,     3,
      81,    63,    65,    30,    66,    67,    38,    88,    -2,     1,
      31,    99,   102,     2,     3,   107,   114,   120,    14,    65,
      28,    66,    67,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   112,    52,    53,    54,    55,   106,     0,
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    82,     0,     0,     0,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   116,     0,     0,     0,
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   117,     0,     0,     0,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    11,    44,    11,    44,
       0,   100,     0,    30,     0,    30,     0,     0,     0,     0,
      31,     0,    31,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   110,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61
  };

  const signed char
  Parser::yycheck_[] =
  {
      21,     2,    71,     0,     9,    23,    11,     8,     5,    30,
      31,    10,     8,    10,    10,    16,    18,    19,    14,     8,
      10,    18,    40,    20,    42,    14,    47,    48,    49,    50,
       3,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    41,     0,    41,    66,     5,   116,   117,     3,
       4,   120,     6,     6,     8,    10,    10,     7,    12,    13,
      10,     0,     1,    17,    14,    11,     5,     6,    69,     3,
       4,    14,    26,    13,    28,    29,    10,     9,    99,     3,
       4,   102,     6,    17,     8,    11,    10,   108,    12,    13,
       5,     6,    11,    17,    15,     7,     3,     4,    15,     6,
       8,     8,    26,    10,    28,    29,    13,     8,     0,     1,
      17,    10,    10,     5,     6,     8,    12,    27,     5,    26,
      20,    28,    29,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     8,    16,    17,    18,    19,    71,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    11,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     3,     4,     3,     4,
      -1,     8,    -1,    10,    -1,    10,    -1,    -1,    -1,    -1,
      17,    -1,    17,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,     5,     6,    33,    35,    36,    37,    38,    39,
      10,     3,    34,     0,    36,    34,    38,    42,    10,     8,
      10,    14,    34,    11,     5,    40,    41,    42,    40,     4,
      10,    17,    34,    50,    51,    52,    53,    14,    13,    43,
      11,     9,    11,    15,     4,    51,    51,     7,    10,    14,
       7,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    15,     8,    12,    26,    28,    29,    37,    38,
      43,    44,    45,    46,    47,    48,    49,    51,    43,    42,
      43,     8,    11,    51,    51,    54,    51,    51,     8,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    10,
       8,    51,    10,    34,    12,    45,    49,     8,     9,    11,
      15,    51,     8,    51,    12,    51,    11,    11,    45,    45,
      27,    45
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    32,    33,    33,    34,    35,    35,    36,    36,    37,
      37,    37,    38,    39,    39,    39,    40,    40,    40,    41,
      41,    42,    42,    43,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    48,    49,
      49,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    53,    54,    54,    54
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     1,     2,     1,     1,     3,
       6,     6,     1,     6,     6,     5,     0,     1,     1,     1,
       3,     2,     4,     4,     3,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     5,     7,     2,     1,     5,     2,
       3,     4,     1,     3,     3,     3,     3,     3,     2,     3,
       4,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     0,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_CONST", "VOID", "INT", "ASSIGN", "SEMI", "COMMA", "LPAREN",
  "RPAREN", "RBRACE", "LBRACE", "LBRACKET", "RBRACKET", "PLUS", "MINUS",
  "MUL", "DIV", "GREATER", "LESS", "EQUAL", "ELESS", "EGREATER", "NEQUAL",
  "IF", "ELSE", "RETURN", "WHILE", "NEG", "NO_ELSE", "$accept", "program",
  "id", "declaration_list", "declaration", "var_declaration", "var_type",
  "func_declaration", "params", "param_list", "param", "compound_stmt",
  "stmt_list", "stmt", "selection_stmt", "expr_stmt", "iteration_stmt",
  "return_stmt", "array_ref", "expr", "comparision", "numeric", "args", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   113,   113,   114,   117,   121,   122,   125,   126,   129,
     130,   132,   136,   139,   143,   147,   151,   152,   153,   156,
     157,   161,   162,   166,   167,   168,   171,   172,   175,   176,
     177,   178,   179,   180,   184,   185,   188,   189,   192,   195,
     196,   199,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   217,   218,   219,   220,   221,
     222,   225,   228,   229,   230
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
    };
    const int user_token_number_max_ = 286;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= user_token_number_max_)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "parser.y"
} // ccbhj
#line 1480 "parser.cc"

#line 232 "parser.y"

void ccbhj::Parser::error(const Parser::location_type& l, const std::string& m) {
    drv.error(l, m);
}
